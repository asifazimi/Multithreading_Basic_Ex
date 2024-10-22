#include <iostream>
#include <thread>
using namespace std::literals::chrono_literals;

void fun1(std::stop_token stop_token, int value)
{
    while (!stop_token.stop_requested())
    {
        std::cout << value++ << " " << std::flush;
        std::this_thread::sleep_for(200ms);
    }
    std::cout << std::endl;
}

int main() // main thread
{
    std::jthread thread(fun1, 3);
    std::this_thread::sleep_for(3s);
}