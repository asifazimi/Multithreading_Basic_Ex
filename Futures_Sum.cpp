#include <iostream>
#include <future>
#include <vector>

using namespace std;

const int ARRAY_SIZE = 1000000;
const int numTasks = 10;

long long partialSum(const vector<int> &array, int start, int end)
{

    long long localSum = 0;
    for (int i = start; i < end; ++i)
    {
        localSum += array[i];
    }
    return localSum;
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
    vector<future<long long>> futures;
    int rangeSize = ARRAY_SIZE / numTasks;

    // Launch threads to calculate partial sum
    for (int i = 0; i < numTasks; ++i)
    {
        int start = i * rangeSize;
        int end = (i == numTasks - 1) ? ARRAY_SIZE : (i + 1) * rangeSize;
        futures.push_back(async(launch::async, partialSum, ref(array), start, end));
    }

    long long totalSum = 0; // Shared variable
    for (auto &ft : futures)
    {
        totalSum += ft.get();
    }

    cout << "Total sum: " << totalSum << endl;

    return 0;
}
