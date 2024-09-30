#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m; std::cin >> n >> m;
    int a = std::min(n, m), b = std::max(n, m);
    while (n % a != 0 || m % a != 0)
    {
        --a;
    }
    while (b % n != 0 || b % m != 0)
    {
        ++b;
    }

    std::cout << a << '\n' << b << '\n';

}
