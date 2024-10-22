#include <iostream>
#include <thread>

int main()
{

    int counter = 0;
    mutex m;

    std::thread th1([&]()
                    {
        m.lock();
        ++counter;
        m.unlock(); })

        std::thread th2([&]()
                        {
        lock_guard<mutex> guard(m);
        ++counter; })

            th1.join();
    th2.join();

    return 0;
}