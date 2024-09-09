#include <iostream>
#include <list>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::list<int> l;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> tmp;
        if (tmp)
        {
            l.push_back(tmp);
        }
        else
        {
            l.pop_back();
        }
    }
    int sum = 0;
    for (auto &x : l)
    {
        sum += x;
    }
    std::cout << sum << '\n';
}
