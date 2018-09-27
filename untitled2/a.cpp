#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

#include "a.h"


A::A(size_t max_elements, size_t left, size_t rihgt) {
    srand(time(NULL));
    for (size_t i = 0; i < max_elements; ++i) {
        m_vector.push_back(rand() % rihgt + left);
        m_map[i] = rand() % rihgt + left;
    }

    size_t size = rand() % 16;
    m_delete_elements = size < m_vector.size() ? size : rand() % m_vector.size();
}

void A::PrintVector() {
    std::cout << "Vector:\n";
    for (auto & elem : m_vector) {
         std::cout << elem << " ";
    }
    std::cout <<  std::endl;
}

void A::PrintMap() {
    std::cout << "Map:\n";
    for (auto & elem : m_map) {
        std::cout << elem.second << " ";
    }
    std::cout << std::endl;
}

void A::DeleteElevents() {
    DeleteEleventsVector();
}

void A::DeleteEleventsVector() {
    // проверка, если надо удалить больше элементов, чем есть в контейнере
    if (m_delete_elements >= m_vector.size()) {
        m_vector.clear();
        m_map.clear();
        return;
    }

    for (size_t i = 0; i < m_delete_elements; ++i) {
        m_vector.erase(m_vector.begin() + rand() % m_vector.size());
    }
    PrintVector();

    DeleteEleventsMap();
}

void A::DeleteEleventsMap() {
    size_t index;
    auto it = m_map.begin();
    for (size_t i = 0; i < m_delete_elements; ++i) {
        index = rand() % m_map.size();
        for (size_t j = 0; j < index; ++j) {
            ++it;
        }

        m_map.erase(it);
        it = m_map.begin();
    }
    PrintMap();
}

void A::Synchronize() {

    // ищет элемент в std::map
    auto FindInMap = [this] (const std::vector<size_t>::iterator &it_vector) -> bool {
        for (auto it = m_map.begin(); it != m_map.end(); ++it) {
            if (*it_vector == it->second) {
                return true;
            }
        }
        return false;
    };

    // ищет элемент в std::vector
    auto FindInVector = [this] (const std::map<size_t, size_t>::iterator &it_map) -> bool {
        for (auto it = m_vector.begin(); it != m_vector.end(); ++it) {
            if (it_map->second == *it) {
                return true;
            }
        }
        return false;
    };


    // пробег по std::vector
    auto it_vector = m_vector.begin();
    while (it_vector != m_vector.end()) {
        if (!FindInMap(it_vector)) {
            m_vector.erase(std::remove(m_vector.begin(), m_vector.end(), *it_vector), m_vector.end());
        }
        else {
            ++it_vector;
        }
    }

    // пробег по std::map, а std::vector уже почистили
    auto it_map = m_map.begin();
    while (it_map != m_map.end()) {
        if (!FindInVector(it_map)) {
            auto it = it_map;
            ++it;
            while (it != m_map.end()) {
                if (it->second == it_map->second) {
                    m_map.erase(it);
                }
                else {
                    ++it;
                }
            }
            m_map.erase(it_map);
        }

        ++it_map;
    }
    PrintVector();
    PrintMap();
}

