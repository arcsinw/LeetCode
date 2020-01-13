#include <iostream>
#include <string>
#include "assert_helper.h"

using namespace std;

 int combination(int m, int n) {
    unsigned long long ans = 1;

    for(int i = 0; i < n; i++) {
        ans *= (m - i);
        ans /= (i + 1); // 从1开始除，可以保证能够整除
    }

    return ans;
}
int uniquePaths(int m, int n) {
    int a = m + n -2;
    int b = min(n-1, m-1);
    return combination(a, b);
}

int uniquePathsDP(int m, int n) {
    if (m < 0 || n < 0) return 0;
    int dp[100][100];

    for (int i = 0; i < m ; i++) {
        dp[i][0] = 1;
    }

    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    AssertHelper<int>::assert(uniquePaths(3, 2), 3);
    AssertHelper<int>::assert(uniquePathsDP(3, 2), 3);
}
