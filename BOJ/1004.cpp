#include <iostream>
#include <vector>

int pow2(int a)
{
    return a * a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    int x1, y1, x2, y2;
    int n, cx, cy, r;
    int cnt;
    std::pair<bool, bool> arr[64];
    while (t--)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> cx >> cy >> r;
            arr[i] = {pow2(cx - x1) + pow2(cy - y1) < pow2(r),
                      pow2(cx - x2) + pow2(cy - y2) < pow2(r)};
        }
        cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i].first != arr[i].second)
            {
                ++cnt;
            }
        }

        std::cout << cnt << '\n';
    }
}
