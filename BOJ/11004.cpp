#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int temp;
	std::vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}
	std::sort(vec.begin(), vec.end());
	printf("%d\n", vec[k - 1]);
}