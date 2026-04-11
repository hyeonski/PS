#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_N 50
#define T (1 << 0)
#define C (1 << 1)
#define M (1 << 2)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

using namespace std;

int n;
int food[MAX_N][MAX_N];
int faith[MAX_N][MAX_N];

struct Student
{
	int r;
	int c;
	int b;
};

struct Group
{
	Student prim;
	vector<Student> members;
};

unordered_map<int, vector<Group>> map;

void morning()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			faith[i][j] += 1;
		}
	}
}

bool in_range(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int x, int y, bool (&visited)[MAX_N][MAX_N])
{
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;
	Group group;
	group.members.push_back({x, y, faith[x][y]});
	while (!q.empty())
	{
		auto [r, c] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (!in_range(nr, nc))
			{
				continue;
			}
			if (food[nr][nc] == food[x][y] && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				q.push({nr, nc});
				group.members.push_back({nr, nc, faith[nr][nc]});
			}
		}
	}
	Student max = {-1, -1, -1};
	for (auto a : group.members)
	{
		if (a.b > max.b || (a.b == max.b && (a.r < max.r || (a.r==max.r && a.c < max.c))))
		{
			max = a;
		}
	}
	group.prim = max;
	int cnt = 0;
	for (auto a : group.members)
	{
		if (a.r != group.prim.r || a.c != group.prim.c)
		{
			++cnt;
			a.b -= 1;
			faith[a.r][a.c] = a.b;
		}
	}
	group.prim.b += cnt;
	faith[group.prim.r][group.prim.c] = group.prim.b;
	map[food[x][y]].push_back(group);
}

void noon()
{
	bool visited[MAX_N][MAX_N];
	memset(visited, 0, sizeof(visited));
	map.clear();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				bfs(i, j, visited);
			}
		}
	}
}

bool compare(Group &a, Group &b)
{
	if (a.prim.b == b.prim.b)
	{
		if (a.prim.r == b.prim.r)
		{
			return a.prim.c < b.prim.c;
		}
		return a.prim.r < b.prim.r;
	}
	return a.prim.b > b.prim.b;
}

void spread(Student prim, bool (&visited)[MAX_N][MAX_N])
{
	int x = prim.b - 1;
	int dir = prim.b % 4;
	faith[prim.r][prim.c] = 1;

	for (int i = 1; i < n && x > 0; ++i)
	{
		int nr = prim.r + dx[dir] * i;
		int nc = prim.c + dy[dir] * i;
		if (!in_range(nr, nc))
		{
			break;
		}
		if (food[nr][nc] == food[prim.r][prim.c])
		{
			continue;
		}
		if (x > faith[nr][nc])
		{
			x -= (faith[nr][nc] + 1);
			faith[nr][nc] += 1;
			food[nr][nc] = food[prim.r][prim.c];
		}
		else if (x <= faith[nr][nc])
		{
			faith[nr][nc] += x;
			x = 0;
			food[nr][nc] = (food[nr][nc] | food[prim.r][prim.c]);
		}
		visited[nr][nc] = true;
	}
}

void evening()
{
	vector<Group> v;
	v.reserve(3000);
	// 전파 당했는지 확인 용도
	bool visited[MAX_N][MAX_N];
	memset(visited, 0, sizeof(visited));
	// 1 T C M;
	for (auto a : map[T])
	{
		v.push_back(a);
	}
	for (auto a : map[C])
	{
		v.push_back(a);
	}
	for (auto a : map[M])
	{
		v.push_back(a);
	}
	sort(v.begin(), v.end(), compare);
	for (auto g : v)
	{
		auto [prim, members] = g;
		if (visited[prim.r][prim.c])
		{
			continue;
		}
		spread(prim, visited);
	}
	v.clear();
	// 2 TC CM TM
	for (auto a : map[T | C])
	{
		v.push_back(a);
	}
	for (auto a : map[C | M])
	{
		v.push_back(a);
	}
	for (auto a : map[M | T])
	{
		v.push_back(a);
	}
	sort(v.begin(), v.end(), compare);
	for (auto g : v)
	{
		auto [prim, members] = g;
		if (visited[prim.r][prim.c])
		{
			continue;
		}
		spread(prim, visited);
	}
	v.clear();
	// 3 TCM
	for (auto a : map[T | C | M])
	{
		v.push_back(a);
	}
	sort(v.begin(), v.end(), compare);
	for (auto g : v)
	{
		auto [prim, members] = g;
		if (visited[prim.r][prim.c])
		{
			continue;
		}
		spread(prim, visited);
	}
}

void print_result()
{
	int count[200];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			count[food[i][j]] += faith[i][j];
		}
	}
	cout << count[T | C | M]
		 << ' ' << count[T | C] << ' ' << count[M | T] << ' ' << count[C | M]
		 << ' ' << count[M] << ' ' << count[C] << ' ' << count[T] << '\n';
}

void print_now()
{
	cout << "food:" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << food[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "faith:" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << faith[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> n >> t;
	string input;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		for (int j = 0; j < n; ++j)
		{
			switch (input[j])
			{
			case 'T':
				food[i][j] = T;
				break;
			case 'C':
				food[i][j] = C;
				break;
			case 'M':
				food[i][j] = M;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> faith[i][j];
		}
	}
	while (t--)
	{
		morning();
		// print_now();
		noon();
		// print_now();
		evening();
		// print_now();
		print_result();
	}
}