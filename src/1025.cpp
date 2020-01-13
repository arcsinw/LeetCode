#include <iostream>
#include <vector>
#include "assert_helper.h"

using namespace std;

bool divisorGameDP(int N) {
    bool dp[N+1]; // 用false初始化为长度为N+1的dp数组

    for (int i = 2; i <= N; i++) {
        for (int x = 1; x < i; x++) {
            if (i % x == 0) {   // N % x == 0 ?
                dp[i] = dp[i] || !dp[i-x];  // dp[i - x] == false ?
            }
        }
    }

    return dp[N];
}

bool divisorGame(int N) {
    return (N & 1) == 0;
}

int main()
{
    AssertHelper<int>::assert(2, divisorGame(2), 1);
    AssertHelper<int>::assert(3, divisorGame(3), 0);
    AssertHelper<int>::assert(2, divisorGameDP(2), 1);
    AssertHelper<int>::assert(3, divisorGameDP(3), 0);
}
