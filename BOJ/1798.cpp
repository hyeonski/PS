#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long double PI = 3.1415926;
    int angle;
    long double r, h, d1, a1, d2, a2;
    std::cout << std::fixed;
    std::cout.precision(2);
    for (int i = 0; i < 4; ++i)
    {
        std::cin >> r >> h >> d1 >> a1 >> d2 >> a2;
        angle = std::max(a1, a2) - std::min(a1, a2);
        std::cout << sqrtl(powl(d1, 2) + powl(d2, 2) - (2 * d1 * d2 * cosl(angle * (r / sqrtl(powl(h, 2) + powl(r, 2))) * PI / 180))) << '\n';
    }
}
