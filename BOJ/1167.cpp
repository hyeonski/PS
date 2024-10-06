#include <iostream>
#include <vector>
#include <algorithm>

struct edge
{
    int u;
    int v;
    int w;
};

std::vector<struct edge> adjlist[100001];
bool visited[100001];
int max;

int dfs(int v)
{
    int maxpath = 0;
    visited[v] = true;
    std::vector<int> path;
    for (std::vector<struct edge>::size_type i = 0; i < adjlist[v].size(); ++i)
    {
        struct edge &e = adjlist[v][i];
        if (!visited[e.v])
        {
            path.push_back(dfs(e.v) + e.w);
        }
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

    int v;
    std::cin >> v;

    int s, e, w;
    for (int i = 0; i < v; ++i)
    {
        std::cin >> s;
        while (true)
        {
            std::cin >> e;
            if (e == -1)
            {
                break;
            }
            std::cin >> w;
            adjlist[s].push_back({s, e, w});
            adjlist[e].push_back({e, s, w});
        }
    }
    dfs(1);
    std::cout << max << '\n';
}