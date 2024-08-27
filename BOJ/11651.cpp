#include <iostream>
#include <map>
#include <set>

int main()
{
	int n;
	int x, y;
	scanf("%d", &n);

	std::multimap<int, int> map;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		map.insert(std::pair<int, int>(y, x));

	}
	std::multiset<int> set;
	int key = -100000;
	for (std::multimap<int, int>::const_iterator iter = map.begin(); iter != map.end(); )
	{
		key = iter->first;
		while (iter->first == key)
		{
			set.insert(iter->second);
			iter++;
		}
		for (std::multiset<int>::const_iterator set_iter = set.begin(); set_iter != set.end(); set_iter++)
			printf("%d %d\n", *set_iter, key);
		set.clear();
	}
}