#include <iostream>
#include <vector>

#define INF 1 << 29

struct edge
{
    int u;
    int v;
    int w;
};

bool check_neg_cycle(std::vector<std::vector<int>> &adjmat, int n)
{
    std::vector<std::vector<int>> a(adjmat);

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][i] < 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int tc;
    std::cin >> tc;
    int n, m, w;
    int s, e, t;

    while (tc--)
    {
        std::cin >> n >> m >> w;
        std::vector<std::vector<int>> adjmat(501, std::vector<int>(501, INF));
        for (int i = 0; i < m; ++i)
        {
            std::cin >> s >> e >> t;
            if (adjmat[s][e] > t)
            {
                adjmat[s][e] = t;
            }
            if (adjmat[e][s] > t)
            {
                adjmat[e][s] = t;
            }
        }
        for (int i = 0; i < w; ++i)
        {
            std::cin >> s >> e >> t;
            if (adjmat[s][e] > -t)
            {
                adjmat[s][e] = -t;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (adjmat[i][i] == INF)
            {
                adjmat[i][i] = 0;
            }
        }
        std::cout << (check_neg_cycle(adjmat, n) ? "YES" : "NO") << '\n';
    }
}
