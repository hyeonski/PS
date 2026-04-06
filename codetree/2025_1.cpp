#include <iostream>
#include <queue>
#include <list>

#define MAXN 30
#define MAXK 50
#define MAXCLEAN 20

using namespace std;

struct Point
{
	int r;
	int c;

	bool operator==(Point &other)
	{
		return (this->r == other.r) && (this->c == other.c);
	}

	bool operator!=(Point &other)
	{
		return !(*this == other);
	}
};

int map[MAXN][MAXN];
Point robots[MAXK];
int robot_map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int n, k, l;

void bfs(Point &robot, int index)
{
	static int dx[] = {-1, 0, 1, 0};
	static int dy[] = {0, -1, 0, 1};
	memset(visited, false, sizeof(visited));

	list<Point> level;
	list<Point> candid;
	int nr, nc;
	Point temp;
	int minr = -1, minc = -1;
	queue<Point> q;
	visited[robot.r][robot.c] = true;
	for (int i = 0; i < 4; ++i)
	{
		nr = robot.r + dx[i];
		nc = robot.c + dy[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < n && robot_map[nr][nc] == -1 && map[nr][nc] != -1 && !visited[nr][nc])
		{
			q.push({nr, nc});
			visited[nr][nc] = true;
		}
	}
	while (!q.empty())
	{
		level.clear();
		candid.clear();
		while (!q.empty())
		{
			temp = q.front();
			level.push_back(q.front());
			if (map[temp.r][temp.c] > 0)
			{
				candid.push_back(temp);
			}
			q.pop();
			cout << temp.r << ' ' << temp.c << '\n';
		}
		cout << '\n';
		if (candid.size() > 0)
		{
			minr = MAXN + 1;
			minc = MAXN + 1;
			for (auto it = candid.begin(); it != candid.end(); ++it)
			{
				if (it->r < minr || (it->r == minr && it->c < minc))
				{
					minr = it->r;
					minc = it->c;
				}
			}
			break;
		}
		for (auto it = level.begin(); it != level.end(); ++it)
		{
			for (int i = 0; i < 4; ++i)
			{
				nr = it->r + dx[i];
				nc = it->c + dy[i];
				if (0 <= nr && nr < n && 0 <= nc && nc < n && robot_map[nr][nc] == -1 && map[nr][nc] != -1 && !visited[nr][nc])
				{
					q.push({nr, nc});
					visited[nr][nc] = true;
				}
			}
		}
	}
	robot_map[robot.r][robot.c] = -1;
	robot.r = minr;
	robot.c = minc;
	robot_map[minr][minc] = index;
}

void move()
{
	for (int i = 0; i < k; ++i)
	{
		bfs(robots[i], i);
	}
}

int e_clean(int x, int y, int d)
{
	switch (d)
	{
	case 0:
		return min(map[x][y + 1], MAXCLEAN);
		break;
	case 1:
		return min(map[x + 1][y], MAXCLEAN);
		break;
	case 2:
		return min(map[x][y - 1], MAXCLEAN);
		break;
	case 3:
		return min(map[x - 1][y], MAXCLEAN);
		break;
	}
	return -1;
}

int get_direction(Point &robot)
{
	int score[4];
	int x = robot.r, y = robot.c;
	score[0] = e_clean(x, y, 3) + e_clean(x, y, 0) + e_clean(x, y, 1);
	score[1] = e_clean(x, y, 0) + e_clean(x, y, 1) + e_clean(x, y, 2);
	score[2] = e_clean(x, y, 1) + e_clean(x, y, 2) + e_clean(x, y, 3);
	score[3] = e_clean(x, y, 2) + e_clean(x, y, 3) + e_clean(x, y, 0);
	int max = -1, max_i = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (score[i] > max)
		{
			max = score[i];
			max_i = i;
		}
	}
	return max_i;
}

void clean(Point &robot)
{
	static int clean_sum[4]; // 오 아 왼 위
	memset(clean_sum, 0, sizeof(clean_sum));
	int dir = get_direction(robot);
	int amount, cap;
	for (int i = 0; i < 4; ++i)
	{
		switch (dir)
		{
		case 0:
			cap = MAXCLEAN - clean_sum[3];
			amount = min(cap, map[robot.r - 1][robot.c]);
			map[robot.r - 1][robot.c] -= amount;
			clean_sum[3] += amount;

			cap = MAXCLEAN - clean_sum[0];
			amount = min(cap, map[robot.r][robot.c + 1]);
			map[robot.r][robot.c + 1] -= amount;
			clean_sum[0] += amount;

			cap = MAXCLEAN - clean_sum[1];
			amount = min(cap, map[robot.r + 1][robot.c]);
			map[robot.r + 1][robot.c] -= amount;
			clean_sum[1] += amount;

			break;
		case 1:
			cap = MAXCLEAN - clean_sum[0];
			amount = min(cap, map[robot.r][robot.c + 1]);
			map[robot.r][robot.c + 1] -= amount;
			clean_sum[0] += amount;

			cap = MAXCLEAN - clean_sum[1];
			amount = min(cap,map[robot.r + 1][robot.c]);
			map[robot.r + 1][robot.c] -= amount;
			clean_sum[1] += amount;

			cap = MAXCLEAN - clean_sum[2];
			amount = min(cap,map[robot.r][robot.c + 1]);
			map[robot.r][robot.c + 1] -= amount;
			clean_sum[2] += amount;
			break;
		case 2:
			cap = MAXCLEAN - clean_sum[1];
			amount = min(cap,map[robot.r + 1][robot.c]);
			map[robot.r + 1][robot.c] -= amount;
			clean_sum[1] += amount;

			cap = MAXCLEAN - clean_sum[2];
			amount = min(cap,map[robot.r][robot.c - 1]);
			map[robot.r][robot.c - 1] -= amount;
			clean_sum[2] += amount;

			cap = MAXCLEAN - clean_sum[3];
			amount = min(cap,map[robot.r - 1][robot.c]);
			map[robot.r - 1][robot.c] -= amount;
			clean_sum[3] += amount;

			break;
		case 3:
			cap = MAXCLEAN - clean_sum[2];
			amount = min(cap,map[robot.r][robot.c - 1]);
			map[robot.r][robot.c - 1] -= amount;
			clean_sum[2] += amount;

			cap = MAXCLEAN - clean_sum[3];
			amount = min(cap,map[robot.r - 1][robot.c]);
			map[robot.r - 1][robot.c] -= amount;
			clean_sum[3] += amount;

			cap = MAXCLEAN - clean_sum[0];
			amount = min(cap,map[robot.r][robot.c + 1]);
			map[robot.r][robot.c + 1] -= amount;
			clean_sum[0] += amount;
			break;
		}
		dir = (dir + 1) % 4;
	}
}

void clean_all()
{
	for (int i = 0; i < k; ++i)
	{
		clean(robots[i]);
	}
}

void add_dust()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] > 0)
			{
				map[i][j] += 5;
			}
		}
	}
}

void spread_dust()
{
	list<pair<Point, int>> update;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == 0)
			{
				update.push_back({{i, j}, (map[i - 1][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1]) / 10});
			}
		}
	}
	Point t1;
	int t2;
	for (auto it = update.begin(); it != update.end(); ++it)
	{
		t1 = it->first;
		t2 = it->second;
		map[t1.r][t1.c] = t2;
	}
}

void print()
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] > 0)
			{
				sum += map[i][j];
			}
		}
	}
	cout << sum << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> l;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}
	int r, c;
	memset(robot_map, -1, sizeof(robot_map));
	for (int i = 0; i < k; ++i)
	{
		cin >> r >> c;
		robots[i] = {r, c};
		robot_map[r][c] = i;
	}
	for (int i = 0; i < l; ++i)
	{
		// 이동
		move();
		// 청소
		clean_all();
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				cout << map[j][k] << ' ';
			}
			cout << '\n';
		}
		// 먼지축적
		add_dust();
		// 먼지확산
		spread_dust();
		// 출력
		print();
	}
}