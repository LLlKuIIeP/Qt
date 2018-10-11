#include <chrono>
#include "sharedmutexrecursive.h"

SharedMutexRecursive::SharedMutexRecursive() {}

void SharedMutexRecursive::lock() {
    if (!m_lock) {
        m_lock = true;
        m_id = std::this_thread::get_id();
    }
    if (m_lock && m_id == std::this_thread::get_id()) {
        ++m_counter;
    }
    else if (m_lock && m_id != std::this_thread::get_id()) {
        while (m_lock) {
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }
        m_lock = true;
        m_id = std::this_thread::get_id();
        ++m_counter;
    }
}

void SharedMutexRecursive::unlock() {
    if (m_lock && m_id == std::this_thread::get_id()) {
        --m_counter;
        if (m_counter == 0) {
            m_lock = false;
        }
    }
}
