#include <iostream>
#include <thread>

void test(int x)
{
    std::cout << "hello for thread 1" << std::endl;
    std::cout << "args passed is " << x << std::endl;
}
int main()
{
    // basic thread creation
    // {
    //     std::thread thread1(&test, 100);
    //     thread1.join(); // blocks the execution of the main thread until the thread1 finishes its execution
    //     std::cout << "main thread" << std::endl;
    // }

    // thread creation with lambda function
    // {
    //     auto lambda = [](int x)
    //     {
    //         std::cout << "hello for thread 1" << std::endl;
    //         std::cout << "args passed is " << x << std::endl;
    //     };

    //     std::thread thread1(lambda, 100);
    //     thread1.join();

    //     std::cout << "main thread" << std::endl;
    // }

    // multitread creation
    // {

    //     auto lambda = [](int x)
    //     {
    //         std::cout << "hello form thread" << std::this_thread::get_id() << std::endl;
    //         std::cout << "args passed is " << x << std::endl;
    //     };

    //     std::vector<std::thread> threads;

    //     for (int i = 0; i < 10; i++)
    //     {
    //         threads.push_back(std::thread(lambda, i));
    //     }

    //     for (int i = 0; i < 10; i++)
    //     {
    //         threads[i].join();
    //     }

    //     std::cout << "main thread" << std::endl;
    // }

    // jthreads (joinable threads)
    // {

    //     auto lambda = [](int x)
    //     {
    //         std::cout << "hello form thread" << std::this_thread::get_id() << std::endl;
    //         std::cout << "args passed is " << x << std::endl;
    //     };

    //     std::vector<std::jthread> threads;

    //     for (int i = 0; i < 10; i++)
    //     {
    //         threads.push_back(std::jthread(lambda, i));
    //     }
    //     std::cout << "main thread" << std::endl;
    // }
}
