#include <iostream>
#include <map>

int main(void)
{
	std::map<std::string, std::pair<unsigned long long, unsigned long long> > resist;
	resist["black"] = std::pair<unsigned long long, unsigned long long>(0, 1);
	resist["brown"] = std::pair<unsigned long long, unsigned long long>(1, 10);
	resist["red"] = std::pair<unsigned long long, unsigned long long>(2, 100);
	resist["orange"] = std::pair<unsigned long long, unsigned long long>(3, 1000);
	resist["yellow"] = std::pair<unsigned long long, unsigned long long>(4, 10000);
	resist["green"] = std::pair<unsigned long long, unsigned long long>(5, 100000);
	resist["blue"] = std::pair<unsigned long long, unsigned long long>(6, 1000000);
	resist["violet"] = std::pair<unsigned long long, unsigned long long>(7, 10000000);
	resist["grey"] = std::pair<unsigned long long, unsigned long long>(8, 100000000);
	resist["white"] = std::pair<unsigned long long, unsigned long long>(9, 1000000000);

	std::string a;
	std::string b;
	std::string c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cout << ((resist[a].first * 10) + resist[b].first) * resist[c].second << std::endl;
}