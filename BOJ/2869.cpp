#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a, b, v;
    std::cin >> a >> b >> v;
    if (v <= a)
    {
        std::cout << 1 << '\n';
    }
    else
    {
        std::cout << (int)ceil((double)(v - b) / (a - b)) << '\n';
    }
}