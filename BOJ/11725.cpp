#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj_list(n + 1);
    std::vector<bool> visited(n + 1, false);
    int a, b;
    for (int i = 0; i < n - 1; ++i)
    {
        std::cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    std::vector<int> parent(n + 1, 0);
    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        for (auto &x : adj_list[q.front()])
        {
            if (!visited[x])
            {
                visited[x] = true;
                parent[x] = q.front();
                q.push(x);
            }
        }
        q.pop();
    }
    for (int i = 2; i <= n; ++i)
    {
        std::cout << parent[i] << '\n';
    }
}