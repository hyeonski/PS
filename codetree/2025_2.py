from math import ceil

lamps = []
lamps_num = []
last_m = 0
n, m = 0, 0


def add_lamp():
    global last_m
    global m
    max_len, max_i = 0, 0
    for i in range(m - 1):
        len = lamps[i + 1] - lamps[i]
        if len > max_len:
            max_len = len
            max_i = i
    lamps.insert(max_i + 1, ceil((lamps[max_i] + lamps[max_i + 1]) / 2))
    lamps_num.insert(max_i + 1, last_m + 1)
    last_m += 1
    m += 1


def delete_lamp(target):
    global m
    for i in range(len(lamps)):
        if lamps_num[i] == target:
            lamps.pop(i)
            lamps_num.pop(i)
            break
    m -= 1


def get_r():
    global m
    max_len = max(n - lamps[m - 1], lamps[0] - 1) * 2
    for i in range(m - 1):
        leng = lamps[i + 1] - lamps[i]
        if max_len < leng:
            max_len = leng
    if max_len < 0:
        return 0
    return max_len


q = int(input())
for _ in range(q):
    command = list(map(int, input().split()))
    if command[0] == 100:
        n, m = command[1], command[2]
        lamps = command[3:]
        lamps_num = [i for i in range(1, m + 1)]
        last_m = m
    elif command[0] == 200:
        add_lamp()
    elif command[0] == 300:
        delete_lamp(command[1])
    elif command[0] == 400:
        print(get_r())
