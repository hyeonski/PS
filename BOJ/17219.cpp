#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::unordered_map<std::string, std::string> map;
    std::string site, pass;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> site >> pass;
        map[site] = pass;
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> site;
        std::cout << map[site] << '\n';
    }
}