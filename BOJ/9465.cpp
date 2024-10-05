#include <iostream>
#include <algorithm>

int sticker[2][100001];
int dp[2][100001];
int n;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                std::cin >> sticker[i][j];
            }
        }
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        for (int i = 2; i <= n; ++i)
        {
            dp[0][i] = std::max(dp[0][i - 2], dp[1][i - 2]) + sticker[0][i];
            dp[0][i] = std::max(dp[0][i], dp[1][i - 1] + sticker[0][i]);
            dp[1][i] = std::max(dp[0][i - 2], dp[1][i - 2]) + sticker[1][i];
            dp[1][i] = std::max(dp[1][i], dp[0][i - 1] + sticker[1][i]);
        }
        std::cout << std::max(dp[0][n], dp[1][n]) << '\n';
    }
}
