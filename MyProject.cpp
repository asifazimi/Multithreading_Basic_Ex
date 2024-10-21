#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
using namespace std::chrono_literals;

// Refresh the tempreture after 2000ms
void RefreshForecast(std::map<std::string, int> forecastMap)
{
    // To repeat refresh
    while (true)
    {
        for (auto &item : forecastMap)
        {
            item.second++;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        // sleep after refreshing
        std::this_thread::sleep_for(2000ms);
    }
}

int main()
{
    // Weather API
    std::map<std::string, int> forecastMap = {
        {"New York", 15},
        {"Vienna", 20},
        {"Berline", 10},
    };

    std::thread bgWorker(RefreshForecast, forecastMap);

    system("pause>null");
}