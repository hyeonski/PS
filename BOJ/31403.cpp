#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string a, b;
    int c;
    std::cin >> a >> b >> c;
    std::cout << std::stoi(a) + std::stoi(b) - c << '\n';
    std::cout << std::stoi(a + b) - c << '\n';
}
