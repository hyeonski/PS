#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

struct edge
{
    int v, w;
};
using tp = std::tuple<int, int, int>;

bool intree[10001];
std::vector<struct edge> adjlist[10001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, e;
    std::cin >> n >> e;
    int u, v, w;
    while (e--)
    {
        std::cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }

    int cnt = 0, sum = 0;
    intree[1] = true;
    std::priority_queue<tp, std::vector<tp>, std::greater<tp>> pq;
    for (auto &x : adjlist[1])
    {
        pq.push({x.w, 1, x.v});
    }
    while (cnt < n - 1)
    {
        int weight, a, b;
        std::tie(weight, a, b) = pq.top();
        pq.pop();

        if (intree[b])
        {
            continue;
        }
        intree[b] = true;
        sum += weight;
        cnt++;

        for (auto &x : adjlist[b])
        {
            if (!intree[x.v])
            {
                pq.push({x.w, b, x.v});
            }
        }
    }
    std::cout << sum << '\n';
}
