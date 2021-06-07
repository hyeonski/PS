#include <iostream>
#include <vector>

int main()
{
	int n;
	int a, b;
	scanf("%d", &n);
	std::vector<std::pair<int, int> > vec;

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		vec.push_back(std::pair<int, int>(a, b));
	}

	std::vector<std::pair<int, int> >::const_iterator iter = vec.begin();
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", iter->first + iter->second);
		iter++;
	}
}