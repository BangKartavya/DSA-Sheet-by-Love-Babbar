# your code goes here

def canPlace(dist,minD,cows):
    cnt = 1
    last = dist[0]

    for i in range(1,len(dist)):
        if(dist[i]-last >= minD):
            cnt+=1
            last = dist[i]
        
        if(cnt >= cows):
            return True
    
    return False

def main():

    t = int(input())

    while(t):
        nAndC = input()
        n = int(nAndC.split(" ")[0])
        cows = int(nAndC.split(" ")[1])
        dist = []
        for i in range(n):
            d = int(input())
            dist.append(d)
        
        dist.sort()
        
        s = dist[0]
        e = dist[n-1]

        while(s<=e):
            mid = s + (e-s)//2

            if(canPlace(dist,mid,cows)):
                s = mid+1
            else:
                e = mid-1
        
        print(e)

        t-=1

    return 0

if (__name__ == "__main__"):
    main()
