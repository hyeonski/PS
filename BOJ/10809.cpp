#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> arr(26, -1);
    std::string str; std::cin >> str;
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (arr[str[i] - 'a'] == -1)
        {
            arr[str[i]-'a'] = i;
        }
    }
    for (auto &x: arr)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}