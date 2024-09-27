#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int last, n;
    std::cin >> last;
    std::cin >> n;
    bool is_asc;
    if (last > n)
    {
        is_asc = false;
    }
    else
    {
        is_asc = true;
    }
    last = n;
    for (int i = 0; i < 6; ++i)
    {
        std::cin >> n;
        if (is_asc && last > n)
        {
            std::cout << "mixed\n";
            return 0;
        }
        else if (!is_asc && last < n)
        {
            std::cout << "mixed\n";
            return 0;
        }
        last = n;
    }
    std::cout << (is_asc ? "ascending" : "descending") << '\n';
}
