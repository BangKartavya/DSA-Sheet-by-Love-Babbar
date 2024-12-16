AIR = 0
WATER = 1
FIRE = 2


def helper(H: int, A: int, nextPos: int, time: int):
    if H <= 0 or A <= 0:
        return time

    if nextPos == WATER:
        H -= 5
        A -= 10

        if H <= 0 or A <= 0:
            return time

        return helper(H, A, AIR, time + 1)
    elif nextPos == AIR:
        H += 3
        A += 2
        if H > 5 and A > 10:
            return helper(H, A, WATER, time + 1)

        if H > 20:
            return helper(H, A, FIRE, time + 1)

        return time + 1
    else:
        H -= 20
        A += 5

        if H <= 0 or A <= 0:
            return time

        return helper(H, A, AIR, time + 1)


def solve(H: int, A: int):
    H += 3
    A += 2
    if H > 5 and A > 10:
        return helper(H, A, WATER, 1)

    if H > 20:
        return helper(H, A, FIRE, 1)

    return 1


def main():
    t: int = int(input())

    while t:
        H, A = (int(i) for i in list(input().split(" ")))
        print(solve(H, A))
        t -= 1


if __name__ == "__main__":
    main()
