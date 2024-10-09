#include <iostream>
#include <vector>

#define INF (1 << 29)

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adjmat(n + 1, std::vector<int>(n + 1, INF));
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        if (i < n)
        {
            adjmat[i + 1][i + 1] = 0;
        }
        adjmat[a][b] = 1;
        adjmat[b][a] = 1;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (adjmat[i][j] > adjmat[i][k] + adjmat[k][j])
                {
                    adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                }
            }
        }
    }

    int min = INF, min_i = -1, res;
    for (int i = 1; i <= n; ++i)
    {
        res = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            res += adjmat[i][j];
        }
        if (res < min)
        {
            min = res;
            min_i = i;
        }
    }
    std::cout << min_i << '\n';
}
