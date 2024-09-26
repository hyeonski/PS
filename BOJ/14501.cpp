#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    int dp[30][30];

    std::cin >> n;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    dp[0][n] = 0;
    dp[n][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((i - 1) + v[i - 1].first == j)
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::cout << dp[n][n] << '\n';
}