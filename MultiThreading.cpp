#include <iostream>
#include <thread>
#include <vector>

int main()
{

    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i)
    {
        threads.push_back(std::thread([i]()
                                      { std::cout << "thread" << i << std::endl; }));
    }

    std::cout << "main thread" << std::endl;

    for (int i = 0; i < 4; ++i)
    {
        threads[i].join(); // wait for each thread to finish
    }

    return 0;
}
