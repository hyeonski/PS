#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string in;
    std::stack<char> stack;
    bool balanced;
    while (true)
    {
        balanced = true;
        stack = std::stack<char>();
        std::getline(std::cin, in);
        if (in == ".")
        {
            break;
        }
        for (auto &x : in)
        {
            if (x == '(')
            {
                stack.push('(');
            }
            else if (x == '[')
            {
                stack.push('[');
            }
            else if (x == ')')
            {
                if (!stack.empty() && stack.top() == '(')
                {
                    stack.pop();
                }
                else
                {
                    balanced = false;
                    break;
                }
            }
            else if (x == ']')
            {
                if (!stack.empty() && stack.top() == '[')
                {
                    stack.pop();
                }
                else
                {
                    balanced = false;
                    break;
                }
            }
        }
        if (balanced == false || !stack.empty())
        {
            std::cout << "no\n";
        }
        else
        {
            std::cout << "yes\n";
        }
    }
}