#include <iostream>

bool isvalid(int n, int a)
{
    int sum = a;
    while (a > 0)
    {
        sum += (a % 10);
        a /= 10;
    }
    if (sum == n)
    {
        return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (isvalid(n, i))
        {
            std::cout << i << '\n';
            return 0;
        }
    }
    std::cout << 0 << '\n';
    return 0;
}