#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int sum = 0;
    int t;
    for (int i = 0; i < 5; ++i)
    {
        std::cin >> t;
        sum += (t * t);
    }
    std::cout << sum % 10 << '\n';
}
