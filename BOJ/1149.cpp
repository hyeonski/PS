#include <iostream>
#include <algorithm>

int dp[1001][3];
int cost[1001][3];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    int min = std::min(dp[n][0], dp[n][1]);
    min = std::min(min, dp[n][2]);
    std::cout << min << '\n';
}