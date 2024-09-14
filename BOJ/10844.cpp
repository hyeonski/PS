#include <iostream>
#include <algorithm>

unsigned long long int result = 0;
unsigned long long int dp[101][10];
int n;


int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    dp[1][0] = 0;
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i-1][1] % 1000000000;
            } else if (j==9) {
                dp[i][j] = dp[i-1][8] % 1000000000;
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % 1000000000;
            }
        }
    }
    for (int i = 0; i <= 9; ++i) {
        result += dp[n][i];
    }
    std::cout << result % 1000000000 << '\n';
}

