#include <iostream>

using namespace std;

//int fib(int N)
//{
//    if (N <= 1) return N;
//    return fib(N-1) + fib(N-2);
//}

int fib(int first, int second, int N)
{
    if (N < 3)
    {
        return 1;
    }
    if (N == 3)
    {
        return first + second;
    }

    return fib(second, first + second, N-1);
}

int fib(int N)
{
    if (N < 2) {return N;}

    int first = 0;
    int second = 1;
    int sum = 0;

    while (--N)
    {
        sum = first + second;
        first = second;
        second = sum;
    }

    return sum;
}

int fib(int N)
{
    int *vec = new int[N+1];
    vec[0] = 0;
    vec[1] = 1;

    for(int i = 2; i <= N; i++)
    {
        vec[i] = vec[i-1] + vec[i-2];
    }

    return vec[N];
}

int main()
{
    cout << "fib(1, 1, 5): " << fib(1, 1, 5) << endl;
    cout << "fib(2): " << fib(2) << endl;
}
