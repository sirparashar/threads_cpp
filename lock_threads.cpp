#include <iostream>
#include <thread>
#include <mutex>

// mutex is mutial exclusion
//  mutex is used to synchronize the access to shared resources
std::mutex glock;
// using namespace std;
static int shared_value = 0;

void value_increment()
{

    // standard mutex lock and unlock
    // {
    //     glock.lock();
    //     shared_value++;
    //     glock.unlock();
    // }

    // mutex lock_guard
    // lock_guard is a wrapper around mutex that provides a convenient RAII-style mechanism
    // for owning a mutex for the duration of a scoped block
    {
        std::lock_guard<std::mutex> lockGaurd(glock);
        shared_value++;
    }
}

int main()
{

    std::vector<std::thread> threads;

    for (int i = 0; i < 1000; i++)
    {
        threads.push_back(std::thread(value_increment));
    }

    for (int i = 0; i < 1000; i++)
    {
        threads[i].join();
    }

    std::cout << "shared value: " << shared_value << std::endl;
}