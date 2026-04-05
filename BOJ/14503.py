import sys

n, m = map(int, sys.stdin.readline().split())
r, c, d = map(int, sys.stdin.readline().split())
array2d = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

i, j = r, c
count = 0
while True:
    if not visited[i][j]:
        visited[i][j] = 1
        count = count + 1
    if (array2d[i - 1][j] == 0 and visited[i - 1][j] == 0) or (array2d[i][j - 1] == 0 and visited[i][j - 1] == 0) or (
            array2d[i + 1][j] == 0 and visited[i + 1][j] == 0) or (array2d[i][j + 1] == 0 and visited[i][j + 1] == 0):
        d = (d + 3) % 4
        if d == 0 and array2d[i - 1][j] == 0 and visited[i - 1][j] == 0:
            i = i - 1
        elif d == 1 and array2d[i][j + 1] == 0 and visited[i][j + 1] == 0:
            j = j + 1
        elif d == 2 and array2d[i + 1][j] == 0 and visited[i + 1][j] == 0:
            i = i + 1
        elif d == 3 and array2d[i][j - 1] == 0 and visited[i][j - 1] == 0:
            j = j - 1
    else:
        if d == 0 and array2d[i + 1][j] == 0:
            i = i + 1
        elif d == 1 and array2d[i][j - 1] == 0:
            j = j - 1
        elif d == 2 and array2d[i - 1][j] == 0:
            i = i - 1
        elif d == 3 and array2d[i][j + 1] == 0:
            j = j + 1
        else:
            break
print(count)
