#include <iostream>

int main()
{
    std::string buf;
    while (std::getline(std::cin, buf))
    {
        if (buf == "0")
        {
            break;
        }
        std::string rev;
        rev.reserve(buf.size());
        for (std::string::size_type i = 0; i < buf.size(); ++i)
        {
            rev += buf[buf.size() - i - 1];
        }
        if (rev == buf)
        {
            std::cout << "yes\n";
        }
        else
        {
            std::cout << "no\n";
        }
    }
}