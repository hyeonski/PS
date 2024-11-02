#include <iostream>
#include <vector>
#include <queue>

#define INF (1 << 29)

int jump[101];
bool visit[101];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int u, v;
    for (int i = 0; i < n + m; ++i)
    {
        std::cin >> u >> v;
        jump[u] = v;
    }
    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    visit[1] = true;
    int num, dist, next;
    while (!q.empty())
    {
        num = q.front().first;
        dist = q.front().second;
        q.pop();
        if (num == 100)
        {
            break;
        }
        for (int i = 1; i <= 6; ++i)
        {
            if (num + i <= 100)
            {
                next = num + i;
                while (jump[next])
                {
                    next = jump[next];
                }
                if (!visit[next])
                {
                    q.push({next, dist + 1});
                    visit[next] = true;
                }
            }
        }
    }
    std::cout << dist << '\n';
}
