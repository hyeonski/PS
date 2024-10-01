#include <iostream>
#include <vector>
#include <algorithm>

struct item
{
    int w;
    int v;
};

int dp[101][100001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k; std::cin >> n >> k;
    std::vector<struct item> v(n+1);
    for (int i = 1 ; i <= n ; ++i)
    {
        std::cin >> v[i].w >> v[i].v;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (j < v[i].w)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-v[i].w] + v[i].v);
            }
        }
    }
    std::cout << dp[n][k] << '\n';
}