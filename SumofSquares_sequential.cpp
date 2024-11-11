// We want to compute the sum of squares for numbers from 1 to N. Sum = i * i

// N = 1000000 total number to square and sum
// numThreads = 10

#include <iostream>

using namespace std;

const int N = 1000000;

long long sumOfSquares()
{
    long long sum = 0;
    for (int i = 0; i <= N; ++i)
    {
        sum += i * i; //
    }

    return sum;
}

int main()
{

    long long totalSum = sumOfSquares();
    cout << "Total sum of squares: " << totalSum << endl;
    return 0;
}