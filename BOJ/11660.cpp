#include <iostream>

int dp[1025][1025];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cin >> dp[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + dp[i][j];
        }
    }


    int x1, y1, x2, y2;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
    }
}