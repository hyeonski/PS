#include <iostream>

int power2i(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int result = 2;
    for (int i = 0; i < n - 1; ++i)
    {
        result *= 2;
    }
    return result;
}

int main()
{
    int n, r, c;
    std::cin >> n >> r >> c;
    int section, p2i;
    int result = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        section = 0;
        p2i = power2i(i);
        if (r >= p2i)
        {
            section += 2;
            r -= p2i;
        }
        if (c >= p2i)
        {
            section += 1;
            c -= p2i;
        }
        result += (p2i * p2i * section);
    }
    std::cout << result << '\n';
}
