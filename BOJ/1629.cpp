#include <iostream>

typedef unsigned long long int ull;

ull a, b, c, k;

ull power(ull x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return a % c;

    k = power(x / 2) % c;
    if (x % 2 == 0)
        return k * k % c;
    else
        return k * k % c * a % c;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a >> b >> c;
    std::cout << power(b);

    return 0;
}