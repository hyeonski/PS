#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n; std::cin >> n;
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    while (q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    std::cout << q.front() << '\n';
}