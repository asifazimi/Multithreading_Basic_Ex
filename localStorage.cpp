#include <iostream>
#include <thread>

thread_local int counter = 0;

void do_work()
{
    for (int i = 0; i < 100; i++)
    {
        counter++;
        std::cout << counter << std::endl;
    }
}

int main() // main thread
{

    ++counter;

    std::thread th0(do_work);
    th0.join();

    std::cout << counter << std::endl;
    return 0;
}