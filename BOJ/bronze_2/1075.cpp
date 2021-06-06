#include <iostream>

int main()
{
	int n, f;
	std::cin >> n;
	std::cin >> f;

	int temp = (n / 100) * 100;
	int last_two = 0;
	while (1)
	{
		if ((temp + last_two) % f == 0)
			break ;
		last_two++;
	}
	if (last_two < 10)
		std::cout << 0;
	std::cout << last_two << std::endl;
}