#include <iostream>
#include <set>

int main()
{
	int n;
	int c;
	std::cin >> n;

	std::multiset<int> set;
	for (int i = 0; i < n; i++)
	{
		std::cin >> c;
		set.insert(c);
	}
	for (std::multiset<int>::const_iterator iter = set.begin(); iter != set.end(); iter++)
		std::cout << *iter << "\n";
}