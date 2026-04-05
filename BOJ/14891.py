gears = [input().strip() for _ in range(4)]
heads = [0, 0, 0, 0]
k = int(input())

def rotate_one(i, clockwise):
    if clockwise:
        heads[i] = (heads[i] + 7) % 8
    else:
        heads[i] = (heads[i] + 1) % 8

def rotate(i, clockwise, visited):
    visited[i] = True
    if i > 0 and not visited[i - 1]:
        if gears[i][(heads[i] + 6) % 8] != gears[i - 1][(heads[i - 1] + 2) % 8]:
            rotate(i - 1, not clockwise, visited)
    if i < 3 and not visited[i + 1]:
        if gears[i][(heads[i] + 2) % 8] != gears[i + 1][(heads[i + 1] + 6) % 8]:
            rotate(i + 1, not clockwise, visited)
    rotate_one(i, clockwise)

for _ in range(k):
    gear, direction = map(int, input().split())
    visited = [False, False, False, False]
    rotate(gear - 1, direction == 1, visited)

score = 0
for i in range(4):
    if gears[i][heads[i]] == '1':
        score += 2 ** i

print(score)


