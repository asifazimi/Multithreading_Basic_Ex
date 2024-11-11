#include <iostream>
#include <future>
#include <vector>

using namespace std;

const int N = 1000000;
const int numOfTasks = 10;

long long sumOfSquares(int start, int end)
{

    long long localSum = 0;
    for (int i = start; i <= end; ++i)
    {
        localSum += i * i;
    }

    return localSum;
}

int main()
{

    vector<future<long long>> futures;
    int rangeSize = N / numOfTasks;

    for (int i = 0; i < numOfTasks; ++i)
    {
        int start = i * rangeSize + 1;
        int end = (i == numOfTasks - 1) ? N : (i + 1) * rangeSize;
        futures.push_back(async(launch::async, sumOfSquares, start, end));
    }

    // retrieve results from futures and accumulate the total sum
    long long totalSum = 0;
    for (auto &fut : futures)
    {
        totalSum += fut.get(); // totalSum = totalSum + fut.get();
    }

    cout << "Total sum of squares: " << totalSum << endl;

    return 0;
}