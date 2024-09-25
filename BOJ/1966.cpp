#include <iostream>
#include <list>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int k;
    std::cin >> k;
    int n, m, p;
    std::list<std::pair<int, int>> queue;
    while (k--)
    {
        std::cin >> n >> m;
        queue.clear();
        for (int i = 0; i < n; ++i)
        {
            std::cin >> p;
            queue.push_back({i, p});
        }

        int cnt = 1;
        while (!queue.empty())
        {
            p = queue.front().second;
            auto it = ++queue.begin();
            for (; it != queue.end(); ++it)
            {
                if (p < it->second)
                {
                    break;
                }
            }
            if (it != queue.end())
            {
                queue.push_back(queue.front());
            }
            else
            {
                if (queue.front().first == m)
                {
                    std::cout << cnt << '\n';
                    break;
                }
                ++cnt;
            }
            queue.pop_front();
        }
    }
}