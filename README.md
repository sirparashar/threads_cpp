# Threads in C++

This project demonstrates the use of threads in C++ to perform concurrent programming. It includes examples and explanations of how to create, manage, and synchronize threads.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Threads allow a program to operate more efficiently by doing multiple things at the same time. This project provides a comprehensive guide to using threads in C++.

## Getting Started

To get started with this project, clone the repository and compile the code using a C++ compiler that supports C++11 or later.

```sh
git clone https://github.com/yourusername/threads_cpp.git
cd threads_cpp
```

## Usage

Compile the code using the following command:

```sh
g++ -std=c++11 -pthread main.cpp -o main
```

Run the executable:

```sh
./main
```

## Examples

### Creating a Thread

```cpp
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    std::thread t(hello);
    t.join();
    return 0;
}
```

### Synchronizing Threads

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_thread_id(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread ID: " << id << std::endl;
}

int main() {
    std::thread t1(print_thread_id, 1);
    std::thread t2(print_thread_id, 2);

    t1.join();
    t2.join();
    return 0;
}
```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
