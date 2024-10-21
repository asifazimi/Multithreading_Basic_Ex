#include <iostream>
#include <thread>
#include <vector>

void do_work(const std::vector<int> &&vec)
{
    for (auto &v : vec)
    {
        // do something
    }
}

int main()
{

    std::vector<int> vec = {42, 41, 40};

    std::thread th0(do_work, std::move(vec));
    th0.join();

    return 0;
}
