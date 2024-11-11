#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

const int N = 10000000;
const int numThreads = 10;

atomic<long long> totalSum(0);

void sumOfSquares(int start, int end)
{

    long long localSum = 0;
    for (int i = start; i < end; ++i)
    {

        localSum += i * i;
    }
    totalSum.fetch_add(localSum, memory_order_relaxed);
}

int main()
{

    vector<thread> threads;

    int rangeSize = N / numThreads;

    // Launch threads to calculate partial sum
    for (int i = 0; i < numThreads; ++i)
    {
        int start = i * rangeSize + 1;
        int end = (i == numThreads - 1) ? N : (i + 1) * rangeSize;
        threads.push_back(thread(sumOfSquares, start, end));
    }

    // join threads
    for (auto &th : threads)
    {
        th.join();
    }

    cout
        << "Sum of squares: " << totalSum << endl;

    return 0;
}