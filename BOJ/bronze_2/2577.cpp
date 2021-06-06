#include <iostream>
#include <set>

void insert_key(unsigned long long result, std::multiset<int> &set)
{
	if (result >= 10)
		insert_key(result / 10, set);
	set.insert(result % 10);
}

int main()
{
	unsigned long long a, b, c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	unsigned long long result = a * b * c;
	std::multiset<int> set;
	insert_key(result, set);
	for (int i = 0; i < 10; i++)
		std::cout << set.count(i) << std::endl;
}