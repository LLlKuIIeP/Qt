#include <fstream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <future>

#include <cstdio>

#include <QFile>
#include <QDataStream>
#include <QString>

#include <qdebug.h>

#include "parallel_sort.h"

#define MAX_ELEMENTS 1000
#define MAX_THREDS 100


ParallelSort::ParallelSort(QObject *parent)
            : QObject(parent) {
    m_fun_wait = [this] () -> int {
        if (m_pause == 1) {
            while (true) {
                std::this_thread::sleep_for(std::chrono::seconds(2));

                if (m_pause == 0) {
                    break;
                }
                else if (m_pause == 2) {
                    return m_pause;
                }
            }
        }
        else if (m_pause == 2) {
            return m_pause;
        }
        return m_pause;
    };

    m_fun_barrier = [this]() {
            for (auto & elem : m_vec_futures) {
                elem.wait();
            }

            emit signalStartSort();
            SortFiles();
        };
}

void ParallelSort::slot_init_file(SelectFile *file) {
    m_selected_file = file;
}

void ParallelSort::slot_run() {
    ///--------------------------------------------------------------///
    if (m_pause == 2) {
        return;
    }
    ///--------------------------------------------------------------///

    if (!m_selected_file) {
        return;
    }

    m_file_in.open(m_selected_file->GetInputFileName().toStdString());
    if (m_file_in.is_open()) {
        m_fun = [this] () {
            while (true) {
                auto vec = ReadFile();
                if(vec.size() > 1) {
                    std::sort(vec.begin(), vec.end());
                    WriteFile(vec);
                }
                else {
                    return;
                }
            }
        };

        for(size_t i = 0; i < MAX_THREDS; ++i) {
            m_vec_futures.push_back(std::async(std::launch::async, m_fun));
        }
    }
    else {
        qDebug() << "Error opening file";
        return;
    }

    m_barrier = std::async(std::launch::async, m_fun_barrier);  //Вызов функции барьера
}

void ParallelSort::slot_pause() {
    m_pause = 1;
}

void ParallelSort::slot_resume() {
    m_pause = 0;
}

void ParallelSort::slot_stop() {
    m_pause = 2;
}

void ParallelSort::slot_save_file() {
    if (m_number_files == 1) {
        std::ofstream out_file(m_selected_file->GetOutputFileName().toStdString(), std::ios_base::trunc);
        std::string in_file_name(std::to_string(m_number_files) + ".txt");
        std::ifstream in_file(in_file_name);

        long int x;
        in_file >> x;
        out_file << x;

        while (!in_file.eof()) {
            in_file >> x;
            out_file << " " << x;
        }
        out_file.close();
        in_file.close();

        std::remove(in_file_name.c_str());
    }
}

std::vector<long int> ParallelSort::ReadFile() {
    if (m_file_in.is_open()) {

        ///--------------------------------------------------------------///
        if (m_fun_wait() == 2) {
            std::lock_guard<std::mutex> lock_file_in(m_lock_file_in);
            m_file_in.seekg(0, std::ios_base::end);
            return std::vector<long int>();
        }
        ///--------------------------------------------------------------///

        std::vector<long int> vec;
        long int x;

        std::lock_guard<std::mutex> lock_file_in(m_lock_file_in);
        for (size_t i = 0; i < MAX_ELEMENTS & !m_file_in.eof(); ++i) {
            m_file_in >> x;
            vec.push_back(x);
        }
        vec.shrink_to_fit();

        return vec;
    }
    else {
        return std::vector<long int>();
    }
}

void ParallelSort::WriteFile(std::vector<long> &vec) {
    std::lock_guard<std::mutex> lock_file_out(m_lock_file_out);

    ///--------------------------------------------------------------///
    if (m_fun_wait() == 2) {
        return;
    }
    ///--------------------------------------------------------------///

    std::ofstream out_file(std::to_string(++m_number_files) + ".txt", std::ios_base::trunc);
    if (out_file.is_open()) {

        out_file << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            out_file  << " " << vec[i];
        }
    }
    else {
        qDebug() << "Error writing file";
    }

    out_file.close();
}

void ParallelSort::SortFiles() {
    auto fun_sort = [this] (size_t in_file_1, size_t in_file_2, size_t out_file) {
        ///--------------------------------------------------------------///
        if (m_fun_wait() == 2) {
            return;
        }
        ///--------------------------------------------------------------///

        std::ifstream file_in_1(std::to_string(in_file_1) + ".txt");
        std::ifstream file_in_2(std::to_string(in_file_2) + ".txt");

        long int x1, x2;

        if (file_in_1.is_open() & file_in_2.is_open()) {
            std::ofstream of_file(std::to_string(out_file) + "_.txt", std::ios_base::trunc);

            auto read_local_in_file_1 = [&file_in_1, &x1] () -> bool {
                if (!file_in_1.eof()) {
                    file_in_1 >> x1;
                    return true;
                }
                return false;
            };

            auto read_local_in_file_2 = [&file_in_2, &x2] () -> bool {
                if (!file_in_2.eof()) {
                    file_in_2 >> x2;
                    return true;
                }
                return false;
            };

            bool read_in_file_1 = read_local_in_file_1();
            bool nread_in_file_2 = read_local_in_file_2();
            while (true) {

                ///--------------------------------------------------------------///
                if (m_fun_wait() == 2) {
                    return;
                }
                ///--------------------------------------------------------------///

                if (read_in_file_1 & nread_in_file_2) {
                    if (x1 < x2) {
                         of_file << " " << x1;
                         read_in_file_1 = read_local_in_file_1();
                    }
                    else {
                        of_file << " " << x2;
                        nread_in_file_2 = read_local_in_file_2();
                    }
                }
                else if (!read_in_file_1 & nread_in_file_2) {
                    of_file << " " << x2;
                    nread_in_file_2 = read_local_in_file_2();
                }
                else if (read_in_file_1 & !nread_in_file_2) {
                    of_file << " " << x1;
                    read_in_file_1 = read_local_in_file_1();
                }
                else {
                    file_in_1.close();
                    file_in_2.close();
                    of_file.close();

                    std::string file_1 = std::to_string(in_file_1) + ".txt";
                    std::remove(file_1.c_str());

                    std::string file_2 = std::to_string(in_file_2) + ".txt";
                    std::remove(file_2.c_str());

                    std::string out_file_old = std::to_string(out_file) + "_.txt";
                    std::string out_file_new = std::to_string(out_file) + ".txt";
                    std::lock_guard<std::mutex> rename(m_rename);

                    while (std::rename(out_file_old.c_str(), out_file_new.c_str())) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(50));
                        qDebug() << "ERROR rename:" << out_file_old.c_str() << out_file_new.c_str();
                        ///--------------------------------------------------------------///
                        if (m_fun_wait() == 2) {
                            return;
                        }
                        ///--------------------------------------------------------------///
                    }
                    return;
                }
            }

        }
        return;
    };

    m_vec_futures.clear();

    while (m_number_files > 1) {
        emit signalStepSort(static_cast<int>(m_number_files));

        size_t min_files_out = 1;
        while (min_files_out <= m_number_files) {

            ///--------------------------------------------------------------///
            if (m_fun_wait() == 2) {

                for (auto & elem : m_vec_futures) {
                    elem.wait();
                }
                 return;
            }
            ///--------------------------------------------------------------///

            for (size_t i = min_files_out, j = 0; i < m_number_files; i += 2) {
                if (j < MAX_THREDS) {
                    std::lock_guard<std::mutex> lock_file_out(m_lock_file_out);
                    m_vec_futures.push_back(std::async(std::launch::async, fun_sort, i, i + 1, ++m_number_files_out));
                    ++j;
                }
                else {
                    break;
                }
            }

            for (auto & elem : m_vec_futures) {
                elem.wait();
            }
            m_vec_futures.clear();
            min_files_out += MAX_THREDS * 2;

        }
        if (m_number_files % 2 == 1) {

            std::string file_out_old = std::to_string(m_number_files) + ".txt";
            std::string file_out_new = std::to_string(m_number_files_out + 1) + ".txt";
            std::lock_guard<std::mutex> rename(m_rename);
            while (std::rename(file_out_old.c_str(), file_out_new.c_str())) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                qDebug() << "ERROR rename:" << file_out_old.c_str() << file_out_new.c_str();
            }

            std::lock_guard<std::mutex> lock_file_out(m_lock_file_out);
            ++m_number_files_out;
        }

        m_number_files = m_number_files_out;
        m_number_files_out = 0;
    }

    emit signalStepSort(static_cast<int>(m_number_files));
    emit signalStopSort();
}


