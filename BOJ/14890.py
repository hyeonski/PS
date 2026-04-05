import sys

input = sys.stdin.readline

n, l = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]


def can_place_slope(road, used, start):
    if start < 0 or start + l > n:
        return False

    height = road[start]
    for idx in range(start, start + l):
        if road[idx] != height or used[idx]:
            return False

    return True


def mark_slope(used, start):
    for idx in range(start, start + l):
        used[idx] = True


def is_passable(road):
    used = [False] * n
    idx = 0

    while idx < n - 1:
        current = road[idx]
        next_height = road[idx + 1]

        if current == next_height:
            idx += 1
            continue

        if abs(current - next_height) > 1:
            return False

        # 오르막: 현재 칸을 기준으로 왼쪽에 길이 l의 평지가 필요하다.
        if current + 1 == next_height:
            start = idx - l + 1
            if not can_place_slope(road, used, start):
                return False
            mark_slope(used, start)
            idx += 1
            continue

        # 내리막: 다음 칸을 기준으로 오른쪽에 길이 l의 평지가 필요하다.
        start = idx + 1
        if not can_place_slope(road, used, start):
            return False
        mark_slope(used, start)
        idx += l

    return True


count = 0

for row in grid:
    if is_passable(row):
        count += 1

for col in zip(*grid):
    if is_passable(list(col)):
        count += 1

print(count)