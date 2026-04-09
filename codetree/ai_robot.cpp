#include <iostream>
#include <queue>
#include <cstring>

#define MAXN 30
#define MAXK 50
#define MAXCLEAN 20


using namespace std;

// Point: 격자 위의 좌표를 표현한다.
// 로봇 위치, BFS 탐색 위치 모두 이 구조체를 사용한다.

struct Point
{
	int r;
	int c;

	bool operator==(const Point &other) const
	{
		return r == other.r && c == other.c;
	}

	bool operator!=(const Point &other) const
	{
		return !(*this == other);
	}
};

// map: 현재 격자의 먼지 상태
//   -1 : 벽
//    0 : 빈 칸
//   양수 : 먼지의 양
// next_map: 확산 결과를 임시로 저장하는 배열
// robots: 각 로봇의 현재 위치
// robot_map: 해당 칸에 어떤 로봇이 있는지 표시 (-1이면 없음)
// visited: BFS 방문 배열
int map[MAXN][MAXN];
int next_map[MAXN][MAXN];
Point robots[MAXK];
int robot_map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int n, k, l;

// 격자 범위 안인지 확인한다.
bool in_range(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < n;
}

// BFS에서 같은 거리의 오염 칸이 여러 개 나오면
// 행이 더 작은 칸, 행이 같으면 열이 더 작은 칸을 우선한다.
bool is_better_target(const Point &a, const Point &b)
{
	if (a.r != b.r)
		return a.r < b.r;
	return a.c < b.c;
}

// 한 로봇을 가장 가까운 오염 칸으로 이동시킨다.
// 같은 거리라면 (행, 열) 우선순위가 더 앞선 칸으로 이동한다.
// 현재 칸에 이미 먼지가 있으면 이동하지 않는다.
void bfs(Point &robot, int index)
{
	static int dx[] = {-1, 0, 0, 1};
	static int dy[] = {0, -1, 1, 0};

	// 현재 칸에 먼지가 있으면 이미 청소할 대상이 있으므로 이동하지 않는다.
	if (map[robot.r][robot.c] > 0)
		return;

	memset(visited, 0, sizeof(visited));

	queue<Point> q;
	q.push(robot);
	visited[robot.r][robot.c] = true;

	// BFS를 거리 레벨 단위로 진행한다.
	// 현재 거리에서 발견한 오염 칸 후보들 중 가장 우선순위가 높은 칸을 고른다.
	while (!q.empty())
	{
		int qsize = (int)q.size();
		Point best;
		bool found = false;

		// 같은 거리의 칸들을 한 번에 처리한다.
		for (int s = 0; s < qsize; ++s)
		{
			Point cur = q.front();
			q.pop();

			// 상, 좌, 우, 하 순서로 탐색한다.
			// 다만 tie-break는 found 후보들끼리 직접 비교해서 확정한다.
			for (int dir = 0; dir < 4; ++dir)
			{
				int nr = cur.r + dx[dir];
				int nc = cur.c + dy[dir];

				if (!in_range(nr, nc))
					continue;
				if (visited[nr][nc])
					continue;
				if (map[nr][nc] == -1)
					continue;
				if (robot_map[nr][nc] != -1)
					continue;

				visited[nr][nc] = true;

				if (map[nr][nc] > 0)
				{
					Point candidate;
					candidate.r = nr;
					candidate.c = nc;
					if (!found || is_better_target(candidate, best))
					{
						best = candidate;
						found = true;
					}
				}
				else
				{
					Point next;
					next.r = nr;
					next.c = nc;
					q.push(next);
				}
			}
		}

		// 현재 거리에서 오염 칸을 하나라도 찾았다면
		// 그중 가장 우선순위가 높은 칸으로 이동하고 BFS를 종료한다.
		if (found)
		{
			robot_map[robot.r][robot.c] = -1;
			robot = best;
			robot_map[robot.r][robot.c] = index;
			return;
		}
	}
}

// 모든 로봇을 순서대로 이동시킨다.
void move()
{
	for (int i = 0; i < k; ++i)
	{
		bfs(robots[i], i);
	}
}

// 해당 칸에서 실제로 청소 가능한 양을 반환한다.
// 한 칸에서는 최대 20까지만 청소할 수 있다.
int get_clean_amount(int r, int c)
{
	if (!in_range(r, c))
		return 0;
	if (map[r][c] <= 0)
		return 0;
	return min(map[r][c], MAXCLEAN);
}

// 로봇 하나가 청소를 수행한다.
// 현재 칸과 상하좌우 중 한 방향을 제외한 3칸, 총 최대 4칸을 청소한다.
// 어느 방향을 제외할지에 따라 청소 가능한 양이 달라지므로,
// 4가지 경우를 모두 비교해서 가장 많이 청소되는 방향을 고른다.
// 동점이면 문제에서 정한 방향 우선순위를 따른다.
void clean(Point &robot)
{
	// 방향 인덱스: 0=오른쪽, 1=아래, 2=왼쪽, 3=위
	static int dr[] = {0, 1, 0, -1}; // 오른쪽, 아래, 왼쪽, 위
	static int dc[] = {1, 0, -1, 0};
	static int exclude_priority[] = {2, 3, 0, 1}; // 왼쪽 > 위쪽 > 오른쪽 > 아래쪽

	int best_exclude = exclude_priority[0];
	int best_sum = -1;

	// 제외할 방향을 하나씩 시도해 보면서
	// 실제로 청소 가능한 양의 합이 최대가 되는 방향을 찾는다.
	for (int order = 0; order < 4; ++order)
	{
		int exclude_dir = exclude_priority[order];
		int total = get_clean_amount(robot.r, robot.c);

		for (int dir = 0; dir < 4; ++dir)
		{
			if (dir == exclude_dir)
				continue;
			total += get_clean_amount(robot.r + dr[dir], robot.c + dc[dir]);
		}

		if (total > best_sum)
		{
			best_sum = total;
			best_exclude = exclude_dir;
		}
	}

	// 현재 칸부터 실제 청소를 적용한다.
	if (map[robot.r][robot.c] > 0)
	{
		map[robot.r][robot.c] -= min(map[robot.r][robot.c], MAXCLEAN);
	}

	for (int dir = 0; dir < 4; ++dir)
	{
		if (dir == best_exclude)
			continue;

		int nr = robot.r + dr[dir];
		int nc = robot.c + dc[dir];
		if (!in_range(nr, nc))
			continue;
		if (map[nr][nc] <= 0)
			continue;

		map[nr][nc] -= min(map[nr][nc], MAXCLEAN);
	}
}

// 모든 로봇이 순서대로 청소를 수행한다.
void clean_all()
{
	for (int i = 0; i < k; ++i)
	{
		clean(robots[i]);
	}
}

// 남아 있는 먼지는 각 턴마다 5씩 증가한다.
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

// 빈 칸(0인 칸)은 상하좌우의 먼지 영향을 받아 먼지가 생긴다.
// 이때 이번 턴의 확산은 동시에 일어나야 하므로 next_map에 먼저 기록한 뒤,
// 마지막에 map에 한꺼번에 반영한다.
void spread_dust()
{
	static int dx[] = {-1, 1, 0, 0};
	static int dy[] = {0, 0, -1, 1};

	// 현재 상태를 next_map에 복사해 두고,
	// 여기에 확산으로 늘어나는 먼지를 더한다.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			next_map[i][j] = map[i][j];
		}
	}

	// 빈 칸만 확산의 대상이 된다.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] != 0)
				continue;

			int sum = 0;
			for (int dir = 0; dir < 4; ++dir)
			{
				int ni = i + dx[dir];
				int nj = j + dy[dir];
				if (!in_range(ni, nj))
					continue;
				if (map[ni][nj] == -1)
					continue;
				if (map[ni][nj] > 0)
					sum += map[ni][nj];
			}
			next_map[i][j] += sum / 10;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			map[i][j] = next_map[i][j];
		}
	}
}

// 현재 격자에 남아 있는 전체 먼지의 양을 출력한다.
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

// 입력을 받고, l번 턴을 시뮬레이션한다.
// 한 턴의 순서는 이동 -> 청소 -> 먼지 증가 -> 확산 -> 출력 이다.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> l;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	memset(robot_map, -1, sizeof(robot_map));

	for (int i = 0; i < k; ++i)
	{
		int r, c;
		cin >> r >> c;
		--r;
		--c;
		robots[i].r = r;
		robots[i].c = c;
		robot_map[r][c] = i;
	}

	for (int turn = 0; turn < l; ++turn)
	{
		move();
		clean_all();
		add_dust();
		spread_dust();
		print();
	}

	return 0;
}