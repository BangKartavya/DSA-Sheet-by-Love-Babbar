def solve(x:list[int],y:list[int],n):
    x.sort()
    y.sort()

    prevX:int = x[0]
    prevY: int = y[0]

    i: int = 1

    mdx: int = prevX
    mdy: int = prevY

    while(i <= n):
        curX: int = x[i]
        curY: int = y[i]

        mdx = max(mdx,curX-prevX)
        mdy = max(mdy,curY-prevY)

        prevX = curX
        prevY = curY

        i+=1
    
    return (mdx-1) * (mdy - 1)


def main():
    t: int = int(input())

    while(t):
        w,h,n = (int(i) for i in list(input().split(" ")))
        
        x: list[int] = [0]*(n+1)
        y: list[int] = [0]*(n+1)

        for i in range(n):
            x[i],y[i] = (int(j) for j in list(input().split(" ")))

        x[n] = w+1
        y[n] = h+1
        print(solve(x,y,n))
        t-=1


if(__name__ == "__main__"):
    main()