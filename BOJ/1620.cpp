#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string buf;
    std::unordered_map<std::string, int> strint;
    std::unordered_map<int, std::string> intstr;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> buf;
        strint[buf] = i;
        intstr[i] = buf;
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> buf;
        if (isdigit(buf[0]))
        {
            std::cout << intstr[std::stoi(buf)] << '\n';
        }
        else
        {
            std::cout << strint[buf] << '\n';
        }
    }
}