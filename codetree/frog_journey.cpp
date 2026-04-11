#include <iostream>
#include <queue>
#include <limits>

using namespace std;

#define MAX_N 50
#define SAFE '.'
#define SLIP 'S'
#define ENEMY '#'

const int INF = numeric_limits<int>::max();
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n;
char board[MAX_N + 1][MAX_N + 1];

struct Node
{
	int cur_dist;
	int k;
	pair<int, int> point;
};

struct greater_node
{
	bool operator()(const Node &a, const Node &b)
	{
		return a.cur_dist > b.cur_dist;
	}
};

bool in_range(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < n;
}

bool can_jump(int r, int c, int dir, int k)
{
	for (int step = 1; step <= k; ++step)
	{
		int nr = r + dx[dir] * step;
		int nc = c + dy[dir] * step;
		if (!in_range(nr, nc))
		{
			return false;
		}
		if (board[nr][nc] == ENEMY)
		{
			return false;
		}
	}

	int nr = r + dx[dir] * k;
	int nc = c + dy[dir] * k;
	return board[nr][nc] == SAFE;
}

void journey(int r1, int c1, int r2, int c2)
{
	int dist[MAX_N + 1][MAX_N + 1][6];
	bool visited[MAX_N + 1][MAX_N + 1][6];
	priority_queue<Node, vector<Node>, greater_node> pq;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 1; k <= 5; ++k)
			{
				dist[i][j][k] = INF;
				visited[i][j][k] = false;
			}
		}
	}

	dist[r1][c1][1] = 0;
	pq.push({0, 1, {r1, c1}});

	while (!pq.empty())
	{
		auto [cur_dist, k, u] = pq.top();
		pq.pop();

		auto [x, y] = u;
		if (visited[x][y][k])
		{
			continue;
		}
		visited[x][y][k] = true;

		if (x == r2 && y == c2)
		{
			cout << cur_dist << '\n';
			return;
		}

		// 1) 현재 점프력 k로 정확히 k칸 점프 (비용 1)
		for (int dir = 0; dir < 4; ++dir)
		{
			if (!can_jump(x, y, dir, k))
			{
				continue;
			}

			int nx = x + dx[dir] * k;
			int ny = y + dy[dir] * k;
			if (dist[nx][ny][k] > cur_dist + 1)
			{
				dist[nx][ny][k] = cur_dist + 1;
				pq.push({dist[nx][ny][k], k, {nx, ny}});
			}
		}

		// 2) 점프력 증가: k -> k + 1 (비용 (k + 1)^2)
		if (k < 5)
		{
			int next_k = k + 1;
			int next_dist = cur_dist + next_k * next_k;
			if (dist[x][y][next_k] > next_dist)
			{
				dist[x][y][next_k] = next_dist;
				pq.push({next_dist, next_k, {x, y}});
			}
		}

		// 3) 점프력 감소: k -> smaller_k (비용 1)
		for (int smaller_k = 1; smaller_k < k; ++smaller_k)
		{
			if (dist[x][y][smaller_k] > cur_dist + 1)
			{
				dist[x][y][smaller_k] = cur_dist + 1;
				pq.push({cur_dist + 1, smaller_k, {x, y}});
			}
		}
	}

	cout << -1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	string line;
	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < n; ++j)
		{
			board[i][j] = line[j];
		}
	}
	int q;
	cin >> q;
	int r1, c1, r2, c2;
	while (q--)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		journey(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
	}
}
