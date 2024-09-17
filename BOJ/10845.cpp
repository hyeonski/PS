#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::string op;
    int k;
    std::queue<int> q;
    while (n--)
    {
        std::cin >> op;
        if (op == "push")
        {
            std::cin >> k;
            q.push(k);
        }
        else if (op == "pop")
        {
            if (q.empty())
            {
                std::cout << -1 << '\n';
                continue;
            }
            std::cout << q.front() << '\n';
            q.pop();
        }
        else if (op == "size")
        {
            std::cout << q.size() << '\n';
        }
        else if (op == "empty")
        {
            std::cout << q.empty() << '\n';
        }
        else if (op == "front")
        {
            if (q.empty())
            {
                std::cout << -1 << '\n';
                continue;
            }
            std::cout << q.front() << '\n';
        }
        else if (op == "back")
        {
            if (q.empty())
            {
                std::cout << -1 << '\n';
                continue;
            }
            std::cout << q.back() << '\n';
        }
    }
}