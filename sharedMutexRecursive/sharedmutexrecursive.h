#pragma once

#include <pthread.h>
#include <atomic>
#include <thread>

class SharedMutexRecursive
{
public:
    SharedMutexRecursive();

    SharedMutexRecursive(const SharedMutexRecursive&) = delete;
    SharedMutexRecursive(SharedMutexRecursive&&) = delete;
    SharedMutexRecursive& operator=(const SharedMutexRecursive&) = delete;
    SharedMutexRecursive& operator=(SharedMutexRecursive&&) = delete;

    void lock();
    void unlock();

private:
    std::atomic_bool m_lock{false};
    std::thread::id m_id{0};

    std::atomic_uint m_counter{0};
};
