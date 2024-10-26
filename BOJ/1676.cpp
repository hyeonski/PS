#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    int two = 0;
    int five = 0;
    int ten = 0;
    int num;
    for (int i = 1; i <= n; ++i)
    {
        num = i;
        while (num / 10 > 0 && num % 10 == 0)
        {
            num /= 10;
            ++ten;
        }
        while (num / 5 > 0 && num % 5 == 0)
        {
            num /= 5;
            ++five;
        }
        while (num / 2 > 0 && num % 2 == 0)
        {
            num /= 2;
            ++two;
        }
    }
    std::cout << ten + (two > five ? five : two) << '\n';
}
