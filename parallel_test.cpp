#include <iostream>
#include <thread>
using namespace std::literals::chrono_literals;

static bool is_Finished = false;

void Do_Work()
{
    while (!is_Finished)
    {
        {
            std::cout << "Working..." << std::endl;
            std::this_thread::sleep_for(1s);
        }
    }

    int main()
    {
        std::thread thread1(Do_Work);

        std::cin.get();
        is_Finished = true;

        thread1.join();
        std::cout << "Finished" << std::endl;

        std::cin.get();
    }