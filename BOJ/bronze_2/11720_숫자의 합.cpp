#include <iostream>
#include <vector>

int main()
{
	int cnt;
	unsigned long long int result = 0;
	std::string nums;

	std::cin >> cnt;
	std::cin >> nums;
	std::string::const_iterator iter = nums.begin();
	for (int i = 0; i < cnt; i++)
	{
		result += (*iter - '0');
		iter++;
	}
	std::cout << result << std::endl;
}