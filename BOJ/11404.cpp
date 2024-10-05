#include <iostream>
#include <algorithm>

#define INF 20000000000

long long int adjmat[101][101];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                adjmat[i][j] = 0;
            }
            else
            {
                adjmat[i][j] = INF;
            }
        }
    }
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> c;
        adjmat[a][b] = std::min(adjmat[a][b], static_cast<long long>(c));
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
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (adjmat[i][j] == INF)
            {
                std::cout << 0 << ' ';
            }
            else
            {
                std::cout << adjmat[i][j] << ' ';
            }
        }
        std::cout << '\n';
    }
}