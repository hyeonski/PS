#include <iostream>
#include <cmath>

int square(int a)
{
    return a * a;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    int x1, y1, r1, x2, y2, r2;
    int dist;
    while (n--)
    {
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        dist = square(x2-x1) + square(y2-y1);

        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        else
        {
            if (square(r1 + r2) == dist || square(r2 - r1) == dist)
            {
                std::cout << 1 << '\n';
            }
            else if (square(r1 + r2) < dist || square(r2 - r1) > dist)
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::cout << 2 << '\n';
            }
        }
    }
}
