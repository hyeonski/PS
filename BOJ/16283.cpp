#include <iostream>

int main()
{
    int a, b, n, w;
    std::cin >> a >> b >> n >> w;
    if (n > w)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    if (a == b)
    {
        if (n * a == w && n == 2)
        {
            std::cout << "1 1" << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
        return 0;
    }
    int numer = b * n - w;
    int denom = b - a;
    if (numer % denom != 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    int x = numer / denom;
    int y = n - x;
    if (x <= 0 || y <= 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << x << " " << y << std::endl;
}
