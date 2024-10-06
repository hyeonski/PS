#include <iostream>
#include <vector>
#include <algorithm>

struct edge
{
    int u;
    int v;
    int w;
};

std::vector<struct edge> adjlist[10001];
int max;

int dfs(int v)
{
    std::vector<int> path(adjlist[v].size());
    int maxpath = 0;
    for (std::vector<struct edge>::size_type i = 0; i < adjlist[v].size(); ++i)
    {
        struct edge &e = adjlist[v][i];
        path[i] = dfs(e.v) + e.w;
    }
    std::sort(path.begin(), path.end(), std::greater<int>());
    if (path.size() < 2)
    {
        for (auto &x : path)
        {
            maxpath += x;
        }
    }
    else
    {
        maxpath = path[0] + path[1];
    }
    if (maxpath > max)
    {
        max = maxpath;
    }
    return path.size() > 0 ? path[0] : 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    int a, b, c;
    for (int i = 0; i < n - 1; ++i)
    {
        std::cin >> a >> b >> c;
        adjlist[a].push_back({a, b, c});
    }
    dfs(1);
    std::cout << max << '\n';
}