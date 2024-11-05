#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n ; std::cin >> n;
    int score, sum;
    std::string input;
    while (n--)
    {
        sum = 0;
        score = 1;
        std::cin >> input;
        for (auto &x: input)
        {
            if (x == 'O')
            {
                sum += (score++);
            }
            else
            {
                score = 1;
            }
        }
        std::cout << sum << '\n';
    }
}
