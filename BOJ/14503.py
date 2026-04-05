import sys

input = sys.stdin.readline

n, m = map(int, input().split())
r, c, d = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

# 북, 동, 남, 서
# 문제의 방향 인덱스와 동일하게 맞춘다.
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

x, y = r, c
cleaned_count = 0

while True:
    # 1. 현재 칸이 아직 청소되지 않았다면 청소한다.
    if not visited[x][y]:
        visited[x][y] = True
        cleaned_count += 1

    # 2. 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인한다.
    has_unclean_empty = False
    for direction in range(4):
        nx = x + dx[direction]
        ny = y + dy[direction]
        if grid[nx][ny] == 0 and not visited[nx][ny]:
            has_unclean_empty = True
            break

    # 3. 주변 4칸 중 청소되지 않은 빈 칸이 있다면,
    #    반시계 방향으로 회전한 뒤 앞칸이 청소되지 않은 빈 칸이면 전진한다.
    if has_unclean_empty:
        d = (d + 3) % 4
        nx = x + dx[d]
        ny = y + dy[d]
        if grid[nx][ny] == 0 and not visited[nx][ny]:
            x, y = nx, ny

    # 4. 주변 4칸 중 청소되지 않은 빈 칸이 없다면,
    #    바라보는 방향을 유지한 채 한 칸 후진한다.
    #    뒤쪽 칸이 벽이면 작동을 멈춘다.
    else:
        back_dir = (d + 2) % 4
        bx = x + dx[back_dir]
        by = y + dy[back_dir]

        if grid[bx][by] == 1:
            break

        x, y = bx, by

print(cleaned_count)
