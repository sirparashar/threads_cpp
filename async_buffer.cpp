#include <iostream>
#include <future>
#include <chrono>

bool bufferData()
{
    size_t bufferSize = 40000;
    while (bufferSize > 0)
    {
        bufferSize -= 1000;
        std::cout << "Buffering data" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    return true;
}

int main()
{
    std::future<bool> backgroundThread = std::async(std::launch::async, bufferData);

    std::future_status status;

    while (true)
    {
        std::cout << "main thread is waiting for buffer data" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));

        if (status == std::future_status::ready)
        {
            std::cout << "buffer data is ready" << std::endl;
            break;
        }
    }

    std::cout << "program ended" << std::endl;

    return 0;
}