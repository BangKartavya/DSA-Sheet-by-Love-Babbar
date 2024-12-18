def main():
    t: int = int(input())

    while t:
        n: int = int(input())
        ones: int = 0
        crude_amps: list[int] = list(int(x) for x in input().split())
        amps: list[int] = []

        for i in range(n):
            if crude_amps[i] == 1:
                ones += 1
            else:
                amps.append(crude_amps[i])

        amps.sort()

        for i in range(ones):
            print(1, end=" ")

        if len(amps) == 2 and amps[0] == 2 and amps[1] == 3:
            print("2 3", end=" ")
        else:
            for i in range(len(amps) - 1, -1, -1):
                print(amps[i], end=" ")

        print()

        t -= 1


if __name__ == "__main__":
    main()
