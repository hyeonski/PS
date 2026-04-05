gears = [input() for _ in range(4)]
heads = [0, 0, 0, 0]
k = int(input())

def rotate_one(i, clockwise):
    if clockwise:
        heads[i] = (heads[i] + 7) % 8
    else:
        heads[i] = (heads[i] + 1) % 8

visited = []
def rotate(i, clockwise):
    visited[i] = 1
    if i != 0 and not visited[i-1]:
        if gears[i][(heads[i] + 6) % 8] != gears[i - 1][(heads[i - 1] + 2) % 8]:
            rotate(i - 1, not clockwise)
    if i != 3 and not visited[i+1]:
        if gears[i][(heads[i] + 2) % 8] != gears[i + 1][(heads[i + 1] + 6) % 8]:
            rotate(i + 1, not clockwise)
    rotate_one(i, clockwise)

for _ in range(k):
    gear, clockwise = input().split()
    visited = [0, 0, 0, 0]
    rotate(int(gear) - 1, True if int(clockwise) == 1 else False)
score = 0
for i in range(4):
    if gears[i][heads[i]] == '1':
        score = score + (2 ** i)
print(score)


