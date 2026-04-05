n, l = map(int, input().split())
map2d = [list(map(int, input().split())) for _ in range(n)]
count = 0


def is_even(road, start):
    for i in range(start + 1, start+l):
        if road[i] != road[start]:
            return False
    return True


def is_marked(mark, start):
    return any(mark[start:start+l])


def can_mark(road, mark, start):
    return is_even(road, start) and (not is_marked(mark, start))


def do_mark(mark, start):
    for i in range(l):
        mark[start + i] = True


def check(num, rowwise):
    road = map2d[num] if rowwise else [map2d[i][num] for i in range(n)]
    mark = [False for _ in range(n)]
    i = 0
    while i < n:
        if i == n - 1:
            break
        if road[i] == road[i + 1]:
            i += 1
        elif road[i] + 1 == road[i + 1] and i + 1 >= l and can_mark(road, mark, i - l + 1):
            do_mark(mark, i - l + 1)
            i += 1
        elif road[i] - 1 == road[i + 1] and i + 1 + l <= n and can_mark(road, mark, i + 1):
            do_mark(mark, i + 1)
            i += l
        else:
            return False
    return True


for i in range(n):
    if check(i, True):
        count += 1

for i in range(n):
    if check(i, False):
        count += 1

print(count)
