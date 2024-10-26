#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    double rt;
    int k = n, flr, cnt = 0;
    while (k > 0)
    {
        rt = sqrt(k);
        flr = floor(rt);
        k -= (flr * flr);
        ++cnt;
    }
    std::cout << cnt << '\n';
}