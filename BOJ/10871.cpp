#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    int in, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        if (in < x)
        {
            std::cout << in << ' ';
        }
    }
}