#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

int N = 1000000;
int numThreads = 20;

long long totalSum = 0;
mutex mtx;

void sumOfSquares(int start, int end)
{

    long long localSum = 0;
    for (int i = start; i <= end; ++i)
    {
        localSum += i * i;
    }

    lock_guard<mutex> lock(mtx);
    totalSum += localSum;
}

int main()
{

    vector<thread> threads;
    int rangeSize = N / numThreads;

    // launch threads to calculate partial sum
    for (int i = 0; i < numThreads; ++i)
    {
        int start = i * rangeSize + 1;
        int end = (i == numThreads - 1) ? N : (i + 1) * rangeSize;
        threads.push_back(thread(sumOfSquares, start, end));
    }

    // To join threads
    for (auto &th : threads)
    {
        th.join();
    }

    cout << "Sum of squares: " << totalSum << endl;
    return 0;
}