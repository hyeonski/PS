#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    int clothes[6];
    int t, p;
    std::cin >> n;
    for (int i = 0; i < 6; ++i)
    {
        std::cin >> clothes[i];
    }
    std::cin >> t >> p;
    int tr = 0;
    for (int i = 0; i < 6; ++i)
    {
        tr += (clothes[i] / t);
        tr += (clothes[i] % t == 0 ? 0 : 1);
    }
    int pr = n / p, remain = n % p;
    std::cout << tr << '\n'
              << pr << ' ' << remain << '\n';
}