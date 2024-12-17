def solve(buy: list[int], sell: list[int]):
    i: int = 0
    j: int = 0

    n: int = len(buy)
    m: int = len(sell)

    total = 0

    while i < n and j < m:
        x: int = min(buy[i][0], sell[j][0])
        diff: int = abs(buy[i][1] - sell[j][1])

        total += x * diff

        buy[i][0] -= x
        sell[j][0] -= x

        if buy[i][0] == 0:
            i += 1
        if sell[j][0] == 0:
            j += 1

    return total


def main():
    n = -1
    while n != 0:
        n = int(input())
        if n == 0:
            return

        a: list[int] = [int(i) for i in input().split(" ")]
        buy: list[int] = []
        sell: list[int] = []

        for i in range(n):
            if a[i] >= 0:
                buy.append([a[i], i])
            else:
                sell.append([-a[i], i])

        print(solve(buy, sell))


if __name__ == "__main__":
    main()
