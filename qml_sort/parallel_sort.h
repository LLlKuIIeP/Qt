#ifndef PARALLEL_SORT_H
#define PARALLEL_SORT_H

#include <fstream>
#include <mutex>
#include <atomic>
#include <thread>
#include <functional>
#include <future>

#include <QObject>
#include <QDebug>

#include "selectfile.h"

class ParallelSort : public QObject
{
    Q_OBJECT
public:
    explicit ParallelSort(QObject *parent = nullptr);

signals:
    void signalStartSort();
    void signalStepSort(int value);
    void signalStopSort();

public slots:
    void slot_init_file(SelectFile *file);
    void slot_run();
    void slot_pause();
    void slot_resume();
    void slot_stop();
    void slot_save_file();

private:
    SelectFile *m_selected_file{nullptr};
    std::mutex m_lock_file_in, m_lock_file_out, m_rename;
    size_t m_number_files{0};
    size_t m_number_files_out{0};
    std::atomic_int m_pause{0};

    std::function<void()> m_fun;
    std::function<int()> m_fun_wait;
    std::function<void()> m_fun_barrier;

    std::ifstream m_file_in;
    std::vector<std::thread> m_vec_threads;
    std::vector<std::future<void>> m_vec_futures;
    std::future<void> m_barrier;

    std::vector<double> ReadFile();
    void WriteFile(std::vector<double>&);
    void SortFiles();
};

#endif // PARALLEL_SORT_H
