def solve(x: list[int], v: list[int], b: int, t: int, k: int):
    can_cnt: int = 0
    cannot_cnt: int = 0
    swaps: int = 0

    n: int = len(x)

    for i in range(n - 1, -1, -1):
        canCover: int = v[i] * t
        toCover: int = b - x[i]

        if canCover >= toCover:
            can_cnt += 1
            if cannot_cnt > 0:
                swaps += cannot_cnt

        else:
            cannot_cnt += 1

        if can_cnt >= k:
            return swaps

    return -1


def main():
    t: int = int(input())

    for _ in range(t):
        n, k, b, t = map(int, input().split())

        x: list[int] = list(int(x) for x in input().split(" "))
        v: list[int] = list(int(x) for x in input().split(" "))

        S: int = solve(x, v, b, t, k)
        if S == -1:
            print(f"Case #{_+1}: IMPOSSIBLE")
        else:
            print(f"Case #{_+1}: {S}")


if __name__ == "__main__":
    main()
