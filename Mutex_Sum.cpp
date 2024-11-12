#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

const int ARRAY_SIZE = 1000000;
const int numThreads = 10;

long long totalSum = 0; // Shared variable
mutex mtx;

void partialSum(const vector<int> &array, int start, int end)
{

    long long localSum = 0;
    for (int i = start; i < end; ++i)
    {
        localSum += array[i];
    }
    lock_guard<mutex> lock(mtx);
    totalSum += localSum;
}

int main()
{

    // Initialize array
    vector<int> array(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = i + 1;
    }

    // Define threads
    vector<thread> threads;
    int rangeSize = ARRAY_SIZE / numThreads;

    // Launch threads to calculate partial sum
    for (int i = 0; i < numThreads; ++i)
    {
        int start = i * rangeSize;
        int end = (i == numThreads - 1) ? ARRAY_SIZE : (i + 1) * rangeSize;
        threads.push_back(thread(partialSum, ref(array), start, end));
    }

    for (auto &th : threads)
    {
        th.join();
    }

    cout << "Total sum: " << totalSum << endl;

    return 0;
}
