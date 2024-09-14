#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int cnt = 0, follow;
    int a = 665, temp;
    do
    {
        ++a;
        follow = 0;
        temp = a;
        while (temp)
        {
            if (temp % 10 == 6)
            {
                ++follow;
            }
            else
            {
                follow = 0;
            }
            if (follow == 3)
            {
                ++cnt;
                break;
            }
            temp /= 10;
        }
    } while (cnt < n);
    std::cout << a << '\n';
}