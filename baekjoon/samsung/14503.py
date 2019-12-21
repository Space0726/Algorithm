def c(r, x, y, d):
    mx = [0,-1,0,1]
    my = [-1,0,1,0]
    cnt = 0
    while True:
        # If current location is not cleaned
        if r[x][y] == 0:
            r[x][y] = 2
            cnt += 1
        t = False
        for i in range(4):
            # Check if cleaned every direction
            if r[x+mx[i]][y+my[i]] == 0:
                t = True
                break
        # If there is any place that is not cleaned
        if t:
            # If left side is not cleaned, move there
            if r[x+mx[d]][y+my[d]] == 0:
                x += mx[d]
                y += my[d]
            # Turn left direction
            d = (d-1) % 4
        # If every side is not cleaned or wall
        else:
            # If back side is wall, end while
            if r[x+mx[d-1]][y+my[d-1]] == 1:
                break
            # If back side is not wall, move back side
            else:
                x += mx[d-1]
                y += my[d-1]
    return cnt

with open("14503_input.txt") as f:
    for _ in range(2):
        n = int(f.readline().split()[0])
        x, y, d = map(int, f.readline().split())
        r = []
        for _ in range(n):
            r.append(list(map(int, f.readline().split())))
        print(c(r, x, y, d))
