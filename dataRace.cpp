#include <iostream>
#include <thread>

unsigned long long counter = 0;

void do_work()
{
    for (int i = 0; i < 100; i++)
    {
        ++counter;
    }
}

int main()
{
    std::thread th1(do_work);
    std::thread th2(do_work);
    th1.join();
    th2.join();

    std::cout << counter << std::endl;

    return 0;
}