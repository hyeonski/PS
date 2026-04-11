#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#define MAX_N 15
#define MAX_Q 50

using namespace std;

struct Microbe
{
	int id;
	int area;
	vector<pair<int, int>> shape;
};

int N;
int board[MAX_N][MAX_N];
int nextId = 1;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

bool in_range(int r, int c)
{
	return 0 <= r && r < N && 0 <= c && c < N;
}

void remove_id(int id)
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (board[r][c] == id)
			{
				board[r][c] = 0;
			}
		}
	}
}

bool is_split(int id)
{
	bool visited[MAX_N][MAX_N];
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	bool found = false;

	for (int r = 0; r < N && !found; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (board[r][c] == id)
			{
				visited[r][c] = true;
				q.push({r, c});
				found = true;
				break;
			}
		}
	}

	if (!found)
	{
		return false;
	}

	while (!q.empty())
	{
		auto [r, c] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (!in_range(nr, nc))
			{
				continue;
			}
			if (visited[nr][nc] || board[nr][nc] != id)
			{
				continue;
			}
			visited[nr][nc] = true;
			q.push({nr, nc});
		}
	}

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (board[r][c] == id && !visited[r][c])
			{
				return true;
			}
		}
	}
	return false;
}

void check_split(const vector<int> &affectedIds)
{
	for (int id : affectedIds)
	{
		if (is_split(id))
		{
			remove_id(id);
		}
	}
}

void add(int r1, int c1, int r2, int c2)
{
	bool seen[MAX_Q + 1];
	memset(seen, 0, sizeof(seen));

	vector<int> affectedIds;
	affectedIds.reserve(MAX_Q);

	for (int r = r1; r < r2; ++r)
	{
		for (int c = c1; c < c2; ++c)
		{
			int id = board[r][c];
			if (id != 0 && !seen[id])
			{
				seen[id] = true;
				affectedIds.push_back(id);
			}
			board[r][c] = nextId;
		}
	}

	check_split(affectedIds);
	++nextId;
}

vector<Microbe> collect_microbes()
{
	int area[MAX_Q + 1];
	int minR[MAX_Q + 1];
	int minC[MAX_Q + 1];
	vector<pair<int, int>> cells[MAX_Q + 1];

	for (int id = 0; id <= MAX_Q; ++id)
	{
		area[id] = 0;
		minR[id] = MAX_N;
		minC[id] = MAX_N;
	}

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			int id = board[r][c];
			if (id == 0)
			{
				continue;
			}
			++area[id];
			minR[id] = min(minR[id], r);
			minC[id] = min(minC[id], c);
			cells[id].push_back({r, c});
		}
	}

	vector<Microbe> microbes;
	microbes.reserve(MAX_Q);

	for (int id = 1; id < nextId; ++id)
	{
		if (area[id] == 0)
		{
			continue;
		}
		Microbe m;
		m.id = id;
		m.area = area[id];
		m.shape.reserve(cells[id].size());
		for (auto [r, c] : cells[id])
		{
			m.shape.push_back({r - minR[id], c - minC[id]});
		}
		microbes.push_back(m);
	}

	sort(microbes.begin(), microbes.end(), [](const Microbe &a, const Microbe &b)
		 {
        if (a.area != b.area) {
            return a.area > b.area;
        }
        return a.id < b.id; });

	return microbes;
}

bool can_place(const int newBoard[MAX_N][MAX_N], const Microbe &m, int baseR, int baseC)
{
	for (auto [rr, cc] : m.shape)
	{
		int nr = baseR + rr;
		int nc = baseC + cc;
		if (!in_range(nr, nc) || newBoard[nr][nc] != 0)
		{
			return false;
		}
	}
	return true;
}

void place_microbe(int newBoard[MAX_N][MAX_N], const Microbe &m, int baseR, int baseC)
{
	for (auto [rr, cc] : m.shape)
	{
		newBoard[baseR + rr][baseC + cc] = m.id;
	}
}

void move()
{
	vector<Microbe> microbes = collect_microbes();
	int newBoard[MAX_N][MAX_N];
	memset(newBoard, 0, sizeof(newBoard));

	for (const Microbe &m : microbes)
	{
		int maxR = 0;
		int maxC = 0;
		for (auto [r, c] : m.shape)
		{
			maxR = max(maxR, r);
			maxC = max(maxC, c);
		}

		bool placed = false;
		for (int r = 0; r + maxR < N && !placed; ++r)
		{
			for (int c = 0; c + maxC < N; ++c)
			{
				if (!can_place(newBoard, m, r, c))
				{
					continue;
				}
				place_microbe(newBoard, m, r, c);
				placed = true;
				break;
			}
		}
	}

	memcpy(board, newBoard, sizeof(board));
}

void record()
{
	int area[MAX_Q + 1];
	memset(area, 0, sizeof(area));

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (board[r][c] != 0)
			{
				++area[board[r][c]];
			}
		}
	}

	set<pair<int, int>> adjacent;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			int cur = board[r][c];
			if (cur == 0)
			{
				continue;
			}

			if (r + 1 < N)
			{
				int other = board[r + 1][c];
				if (other != 0 && other != cur)
				{
					adjacent.insert({min(cur, other), max(cur, other)});
				}
			}
			if (c + 1 < N)
			{
				int other = board[r][c + 1];
				if (other != 0 && other != cur)
				{
					adjacent.insert({min(cur, other), max(cur, other)});
				}
			}
		}
	}

	long long answer = 0;
	for (auto [a, b] : adjacent)
	{
		answer += 1LL * area[a] * area[b];
	}
	cout << answer << '\n';
}

void print_map()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> N >> q;

	int r1, c1, r2, c2;
	while (q--)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		add(r1, c1, r2, c2);
		move();
		record();
	}

	return 0;
}