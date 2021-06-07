#include <iostream>
#include <cstring>

int main()
{
	int n;
	int c;
	int arr[10000];
	
	memset(arr, 0, 10000 * sizeof(int));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c);
		arr[c - 1] += 1;
	}
	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i + 1);
		}
	}
}