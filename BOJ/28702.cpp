#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str[3];
    std::cin >> str[0];
    std::cin >> str[1];
    std::cin >> str[2];
    for (int i = 0; i < 3; ++i)
    {
        if (isdigit(str[i][0]))
        {
            int n = std::stoi(str[i]);
            n = n + (3 - i);
            if (n % 3 == 0)
            {
                if (n % 5 == 0)
                {
                    std::cout << "FizzBuzz\n";
                }
                else
                {
                    std::cout << "Fizz\n";
                }
            }
            else if (n % 5 == 0)
            {
                std::cout << "Buzz\n";
            }
            else
            {
                std::cout << n << '\n';
            }
            break;
        }
    }
}