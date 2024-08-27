#include <iostream>
#include <set>

int main()
{
	int n;
	scanf("%d", &n);
	
	int temp;
	std::multiset<int> set;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		set.insert(temp);
	}
	for (std::multiset<int>::const_iterator iter = set.begin(); iter != set.end(); iter++)
	{
		printf("%d\n", *iter);
	}

}