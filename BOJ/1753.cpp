#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647

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
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int v, e, k;
    std::cin >> v >> e >> k;
    std::vector<std::vector<struct edge>> graph(v + 1);
    std::vector<int> d(v + 1, INF);
    int s, t, w;
    for (int i = 0; i < e; ++i)
    {
        std::cin >> s >> t >> w;
        graph[s].push_back({s, t, w});
    }

    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    pq.push({0, k});
    d[k] = 0;

    int dist, now, cost;
    while (!pq.empty())
    {
        dist = pq.top().first;
        now = pq.top().second;
        pq.pop();
        if (d[now] < dist)
        {
            continue;
        }
        for (auto &x : graph[now])
        {
            cost = dist + x.w;
            if (cost < d[x.v])
            {
                d[x.v] = cost;
                pq.push({cost, x.v});
            }
        }
    }

    for (int i = 1; i <= v; ++i)
    {
        if (d[i] == INF)
        {
            std::cout << "INF" << '\n';
        }
        else
        {
            std::cout << d[i] << '\n';
        }
    }
}
