#include <iostream>
#include <vector>
#include <queue>

#define INF (1 << 29)

struct edge
{
    int u;
    int v;
    int w;
};

struct compare
{
    bool operator()(struct edge &a, struct edge &b)
    {
        return a.w < b.w;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<std::vector<struct edge>> adjlist(n + 1);
    int s, e, t;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> s >> e >> t;
        adjlist[s].push_back({s, e, t});
    }
    std::vector<std::vector<int>> d(n + 1, std::vector<int>(n + 1, INF));
    for (int k = 1; k <= n; ++k)
    {
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;
        pq.push({0, k});
        d[k][k] = 0;

        int dist, now, cost;
        while (!pq.empty())
        {
            dist = pq.top().first;
            now = pq.top().second;
            pq.pop();
            if (d[k][now] < dist)
            {
                continue;
            }
            for (auto &x : adjlist[now])
            {
                cost = dist + x.w;
                if (cost < d[k][x.v])
                {
                    d[k][x.v] = cost;
                    pq.push({cost, x.v});
                }
            }
        }
    }
    int max = 0;
    for (int k = 1; k <= n; ++k)
    {
        if (d[k][x] + d[x][k] > max)
        {
            max = d[k][x] + d[x][k];
        }
    }
    std::cout << max << '\n';
}
