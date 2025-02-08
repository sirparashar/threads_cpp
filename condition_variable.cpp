#include <iostream>
#include <thread>
#include <mutex>

// condition variable is a synchronization primitive that allows one thread to wait
// until specific conditions are met by another thread.

std::mutex glock;
std::condition_variable gcondVariable;

int main()
{

    int res = 0;
    bool notified = false;

    std::thread reporter([&]
                         {

        // unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking,
        // time-constrained attempts at locking, recursive locking, transfer of lock ownership, 
        // and use with condition variables.
        std::unique_lock<std::mutex> lock(glock);
        if(!notified){
            gcondVariable.wait(lock);
        }
        std::cout << "result = "<<res<<std::endl; });

    std::thread mainThread([&]
                           {
        res = 31; 
        notified = true;
        gcondVariable.notify_one(); });

    reporter.join();
    mainThread.join();

    return 0;
}
