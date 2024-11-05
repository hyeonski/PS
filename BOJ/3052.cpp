#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<bool> arr(42, false);
    int n;
    for (int i = 0; i < 10; ++i)
    {
        std::cin >> n;
        arr[n % 42] = true;
    }

    int cnt = 0;
    for (const auto &x : arr)
    {
        if (x)
        {
            ++cnt;
        }
    }
    std::cout << cnt << '\n';
}