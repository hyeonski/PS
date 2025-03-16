#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, b;
    std::cin >> n >> k >> b;
    std::vector<int> outs(b);
    for (int i = 0; i < b; ++i)
    {
        std::cin >> outs[i];
        --outs[i];
    }
    std::sort(outs.begin(), outs.end());
    if (outs[0] >= k)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    if (n - outs[b - 1] - 1 >= k)
    {

        std::cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i < b; ++i)
    {
        if (outs[i] - outs[i - 1] - 1 >= k)
        {
            std::cout << 0 << '\n';
            return 0;
        }
    }
    for (int i = 1; i <= b; ++i)
    {
        for (int j = 0; j + i <= b; ++j)
        {
            int start = j > 0 ? outs[j - 1] + 1 : 0;
            int end = j + i < b ? outs[j + i] : n;
            if (end - start >= k)
            {
                std::cout << i << '\n';
                return 0;
            }
        }
    }
    return 0;
}
