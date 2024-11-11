#include <thread>
#include <atomic>
#include <vector>
#include <iostream>

using namespace std;

// Shared data
atomic<int> counter(0);

void incrementCounter()
{
    for (int i = 0; i < 1000; ++i)
    {
        counter.fetch_add(1, memory_order_relaxed); // Threads will access the counter safely
    }
}

int main()
{

    // To store threads
    vector<thread> threads;

    // To define 10 threads to increment counter
    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(thread(incrementCounter)); // Creating thread
    }

    // To join all threads
    for (auto &th : threads)
    {
        th.join();
    }

    cout << "Final counter value: " << counter << endl;

    return 0;
}