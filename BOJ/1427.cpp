#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string input;
    std::cin >> input;
    std::sort(input.begin(), input.end(), std::greater<int>());
    std::cout << input << '\n';
}