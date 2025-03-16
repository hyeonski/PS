#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> pos(11, -1);
    int cnt = 0;
    int a, b;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        if (pos[a] != -1 && pos[a] != b)
        {
            ++cnt;
        }
        pos[a] = b;
    }
    std::cout << cnt << '\n';
}
