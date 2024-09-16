#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::pair<int, int> arr[n];
    for (int i = 0 ; i < n; ++i) 
    {
        std::cin >> arr[i].first;
        std::cin >> arr[i].second;
    }
    int cnt;
    for (int i = 0; i < n; ++i)
    {
        cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[j].first > arr[i].first && arr[j].second > arr[i].second)
            {
                ++cnt;
            }
        }
        std::cout << cnt + 1 << ' ';
    }
}
