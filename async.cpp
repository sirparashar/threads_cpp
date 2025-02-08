#include <iostream>
#include <future>

// async is a function that runs a function asynchronously (potentially in a separate thread)
// and returns a std::future that will hold the result.

int square(int x)
{
    return x * x;
}

int main()
{
    std::future<int> asyncSquare = std::async(square, 10);

    for (int i = 0; i < 5; i++)
    {
        std::cout << "doing some work" << std::endl;
    }

    int result = asyncSquare.get();

    std::cout << "result = " << result << std::endl;
}