#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_HOUSE 30000 + 10000
#define INF 2147483647

int n;
int max_xi = 1;
map<int, int> town;
map<int, int> town_coord;

void build_house(int p)
{
	// p 좌표에 개미집을 건설한다.
	town[max_xi++] = p;
	town_coord[p] = max_xi - 1;
	++n;
}

void build_town(int num)
{
	int p;
	n = 0;
	while (num--)
	{
		cin >> p;
		build_house(p);
	}
}

void break_house(int q)
{
	// q번 개미집 철거
	map<int, int>::iterator it = town.find(q);
	town_coord.erase(it->second);
	town.erase(it);
	--n;
}

bool can_observe(int d, const vector<int> &pos, int r)
{
	int used = 0;
	int i = 0;
	int sz = (int)pos.size();

	while (i < sz)
	{
		++used;
		if (used > r)
		{
			return false;
		}

		int start = pos[i];
		while (i + 1 < sz && pos[i + 1] - start <= d)
		{
			++i;
		}

		++i;
	}

	return true;
}

void observe(int r)
{
	vector<int> pos;
	pos.reserve(town_coord.size());
	for (map<int, int>::iterator it = town_coord.begin(); it != town_coord.end(); ++it)
	{
		pos.push_back(it->first);
	}

	if (pos.empty())
	{
		cout << 0 << '\n';
		return;
	}

	int lo = 0;
	int hi = 1000000000;
	int ans = hi;

	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (can_observe(mid, pos, r))
		{
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int gq;
	cin >> gq;
	int command;
	int p, q, r;
	while (gq--)
	{
		cin >> command;
		switch (command)
		{
		case 100:
			cin >> n;
			build_town(n);
			break;
		case 200:
			cin >> p;
			build_house(p);
			break;
		case 300:
			cin >> q;
			break_house(q);
			break;
		case 400:
			cin >> r;
			observe(r);
			break;
		}
	}
}