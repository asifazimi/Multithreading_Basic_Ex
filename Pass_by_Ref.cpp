#include <iostream>
#include <thread>
#include <vector>

void do_work(int &x)
{
    x++;
}

int main()
{
    int x = 42;
    std::cout << x << std::endl;

    std::thread th0(do_work, std::ref(x));
    th0.join();

    std::cout << x << std::endl;

    return 0;
}
