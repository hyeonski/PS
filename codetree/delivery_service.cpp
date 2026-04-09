#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <algorithm>

#define MAX_N 50
#define MAX_M 100

using namespace std;

struct Box
{
	int k;
	int h;
	int w;
	int r;
	int c;
};

int n, m;
Box boxs[MAX_M + 1];
int map[MAX_N][MAX_N];

void print_map()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << (map[i][j] / 10 != 0 ? "" : " ") << (map[i][j] == 100 ? -1 : map[i][j]) << ' ';
		}
		cout << endl;
	}
}

void place(Box box)
{
	for (int i = box.r; i < box.r + box.h; ++i)
	{
		for (int j = box.c; j < box.c + box.w; ++j)
		{
			map[i][j] = box.k;
		}
	}
}

void remove(Box box)
{
	for (int i = box.r; i < box.r + box.h; ++i)
	{
		memset(&(map[i][box.c]), 0, sizeof(int) * box.w);
	}
}
void replace(Box o, Box n)
{
	remove(o);
	place(n);
	boxs[o.k] = n;
}

bool drop(Box box)
{
	bool flag = true;
	int x = box.r + box.h;
	for (; x < n; ++x)
	{
		for (int y = box.c; y < box.c + box.w; ++y)
		{
			if (map[x][y] != 0)
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	Box n = box;
	n.r = x - box.h;
	if (box.r == n.r)
	{
		return false;
	}
	replace(box, n);
	return true;
}

void load(Box box)
{
	boxs[box.k] = box;
	place(box);
	drop(box);
}

void collect_affected_boxes(Box removed, vector<int> &affected)
{
	list<int> queue;
	vector<bool> visited(MAX_M + 1, false);

	int x = removed.r - 1;
	if (x < 0)
	{
		return;
	}

	for (int y = removed.c; y < removed.c + removed.w; ++y)
	{
		int id = map[x][y];
		if (id != 0 && !visited[id])
		{
			visited[id] = true;
			queue.push_back(id);
		}
	}

	while (!queue.empty())
	{
		int id = queue.front();
		queue.pop_front();
		affected.push_back(id);

		Box box = boxs[id];
		int upper = box.r - 1;
		if (upper < 0)
		{
			continue;
		}

		for (int y = box.c; y < box.c + box.w; ++y)
		{
			int next_id = map[upper][y];
			if (next_id != 0 && !visited[next_id])
			{
				visited[next_id] = true;
				queue.push_back(next_id);
			}
		}
	}
}

bool compare_drop_order(int a, int b)
{
	if (boxs[a].r != boxs[b].r)
	{
		return boxs[a].r > boxs[b].r; // 아래쪽 상자가 먼저 떨어져야 한다.
	}
	return boxs[a].k < boxs[b].k;
}

void settle_after_unload(Box removed)
{
	vector<int> affected;
	collect_affected_boxes(removed, affected);
	sort(affected.begin(), affected.end(), compare_drop_order);
	for (int i = 0; i < (int)affected.size(); ++i)
	{
		drop(boxs[affected[i]]);
	}
}

void unload_left()
{
	int candid = MAX_M + 100;
	Box tester;
	bool f_candid, f_valid;
	int id;
	for (int x = 0; x < n; ++x)
	{
		f_candid = false;
		for (int y = 0; y < n; ++y)
		{
			if (map[x][y] != 0)
			{
				id = map[x][y];
				f_candid = true;
				break;
			}
		}
		if (f_candid == true)
		{
			if (id > candid)
			{
				continue;
			}
			tester = boxs[id];
			f_valid = true;
			for (int cx = tester.r; cx < tester.r + tester.h; ++cx)
			{
				for (int cy = tester.c - 1; cy >= 0; --cy)
				{
					if (map[cx][cy] != 0)
					{
						f_valid = false;
						break;
					}
				}
				if (f_valid == false)
				{
					break;
				}
			}
			if (f_valid == true)
			{
				if (candid > tester.k)
				{
					candid = tester.k;
				}
				x = tester.r + tester.h - 1;
			}
		}
	}
	if (candid != MAX_M + 100)
	{
		tester = boxs[candid];
		remove(tester);
		cout << tester.k << '\n';
		settle_after_unload(tester);
	}
}

void unload_right()
{
	int candid = MAX_M + 100;
	Box tester;
	bool f_candid, f_valid;
	int id;
	for (int x = 0; x < n; ++x)
	{
		f_candid = false;
		for (int y = n - 1; y >= 0; --y)
		{
			if (map[x][y] != 0)
			{
				id = map[x][y];
				f_candid = true;
				break;
			}
		}
		if (f_candid == true)
		{
			if (id > candid)
			{
				continue;
			}
			tester = boxs[id];
			f_valid = true;
			for (int cx = tester.r; cx < tester.r + tester.h; ++cx)
			{
				for (int cy = tester.c + tester.w; cy < n; ++cy)
				{
					if (map[cx][cy] != 0)
					{
						f_valid = false;
						break;
					}
				}
				if (f_valid == false)
				{
					break;
				}
			}
			if (f_valid == true)
			{
				if (candid > tester.k)
				{
					candid = tester.k;
				}
				x = tester.r + tester.h - 1;
			}
		}
	}
	if (candid != MAX_M + 100)
	{
		tester = boxs[candid];
		remove(tester);
		cout << tester.k << '\n';
		settle_after_unload(tester);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int k, h, w, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> k >> h >> w >> c;
		load({k, h, w, 0, c - 1});
	}
	bool flop = true;
	while (m--)
	{
		// print_map();
		if (flop)
		{
			unload_left();
		}
		else
		{
			unload_right();
		}
		flop = !flop;
	}
}