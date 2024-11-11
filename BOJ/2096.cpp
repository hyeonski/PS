#include <iostream>
#include <vector>

int v[2][3];
int dpmin[2][3];
int dpmax[2][3];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i % 2][0] >> v[i % 2][1] >> v[i % 2][2];
        dpmin[i % 2][0] = v[i % 2][0] + std::min(dpmin[(i - 1) % 2][0], dpmin[(i - 1) % 2][1]);
        dpmin[i % 2][1] = std::min(dpmin[(i - 1) % 2][0], dpmin[(i - 1) % 2][1]);
        dpmin[i % 2][1] = v[i % 2][1] + std::min(dpmin[i % 2][1], dpmin[(i - 1) % 2][2]);
        dpmin[i % 2][2] = v[i % 2][2] + std::min(dpmin[(i - 1) % 2][1], dpmin[(i - 1) % 2][2]);

        dpmax[i % 2][0] = v[i % 2][0] + std::max(dpmax[(i - 1) % 2][0], dpmax[(i - 1) % 2][1]);
        dpmax[i % 2][1] = std::max(dpmax[(i - 1) % 2][0], dpmax[(i - 1) % 2][1]);
        dpmax[i % 2][1] = v[i % 2][1] + std::max(dpmax[i % 2][1], dpmax[(i - 1) % 2][2]);
        dpmax[i % 2][2] = v[i % 2][2] + std::max(dpmax[(i - 1) % 2][1], dpmax[(i - 1) % 2][2]);
    }
    int max, min;
    max = std::max(dpmax[n % 2][0], dpmax[n % 2][1]);
    max = std::max(max, dpmax[n % 2][2]);
    min = std::min(dpmin[n % 2][0], dpmin[n % 2][1]);
    min = std::min(min, dpmin[n % 2][2]);
    std::cout << max << ' ' << min << '\n';
}
