#include <iostream>
#include <vector>
#include <tuple>

int pow2(int a)
{
    return a * a;
}

void dfs(const std::vector<std::vector<int>> &adjlist, std::vector<bool> &visit, int v)
{
    visit[v] = true;
    for (auto &x : adjlist[v])
    {
        if (!visit[x])
        {
            dfs(adjlist, visit, x);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    int n, x, y, r;
    while (t--)
    {
        std::cin >> n;
        std::vector<std::tuple<int, int, int>> v(n);
        std::vector<std::vector<int>> adjlist(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> x >> y >> r;
            v[i] = {x, y, r};
            for (int j = 0; j < i; ++j)
            {
                int a, b, c;
                std::tie(a, b, c) = v[j];
                if (pow2(a - x) + pow2(b - y) <= pow2(r + c))
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        std::vector<bool> visit(n, false);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visit[i])
            {
                dfs(adjlist, visit, i);
                ++cnt;
            }
        }
        std::cout << cnt << '\n';
    }
}
