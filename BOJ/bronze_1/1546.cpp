#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	double temp;

	scanf("%d", &n);
	std::vector<double> vec;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &temp);
		vec.push_back(temp);
	}
	double m = *std::max_element(vec.begin(), vec.end());
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		vec[i] = vec[i] / m * 100;
		result += vec[i];
	}
	result /= n;
	std::cout << result << "\n";
}