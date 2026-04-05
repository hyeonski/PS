from collections import deque

DX = [0, 0, -1, 1]
DY = [-1, 1, 0, 0]

n, m = map(int, input().split())
virus = []
lab = []
for i in range(n):
    row = list(map(int, input().split()))
    for j in range(m):
        if row[j] == 2:
            virus.append((i, j))
    lab.append(row)


def spread_virus(visited):
    q = deque(virus)

    for x, y in virus:
        visited[x][y] = True

    while q:
        x, y = q.popleft()
        for direction in range(4):
            nx = x + DX[direction]
            ny = y + DY[direction]
            if 0 <= nx < n and 0 <= ny < m and lab[nx][ny] == 0 and not visited[nx][ny]:
                visited[nx][ny] = True
                q.append((nx, ny))


def get_area_size():
    visited = [[False for _ in range(m)] for _ in range(n)]
    spread_virus(visited)
    count = 0
    for i in range(n):
        for j in range(m):
            if lab[i][j] == 0 and not visited[i][j]:
                count += 1
    return count


max_size = 0


def backtrack(last_x, last_y, depth):
    global max_size
    if depth == 3:
        area = get_area_size()
        max_size = max(max_size, area)
        return
    for i in range(last_x, n):
        start_y = last_y + 1 if i == last_x else 0
        for j in range(start_y, m):
            if lab[i][j] == 0:
                lab[i][j] = 1
                backtrack(i, j, depth + 1)
                lab[i][j] = 0


backtrack(0, -1, 0)
print(max_size)
