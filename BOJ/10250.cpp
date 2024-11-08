#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    int h, w, n;
    int cnt;
    while (t--)
    {
        std::cin >> h >> w >> n;
        cnt = 1;
        while (n > h)
        {
            n -= h;
            ++cnt;
        }
        std::cout << n;
        if (cnt < 10)
        {
            std::cout << 0;
        }
        std::cout << cnt << '\n';
    }
}