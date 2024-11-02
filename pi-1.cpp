#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// critical section
std::mutex mtx;
void incrementCounter(int &counter, int numberOfIterations)
{

    for (int i = 0; i < numberOfIterations; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); // lock mutex
        counter++;
    }
}

int main()
{

    int counter = 0;
    int num_threads = 4;
    int numberOfIterations = 250;

    // Combine multiple threads
    std::vector<std::thread> threads;

    // Creating multiple threads to increment the counter
    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back(incrementCounter, std::ref(counter), numberOfIterations);
    }

    // Wait for all threads to finish
    for (auto &th : threads)
    {
        th.join();
    }

    std::cout << "Final Counter Value: " << counter << std::endl;
    return 0;
}