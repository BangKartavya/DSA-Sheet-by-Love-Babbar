def possible(freq,mid,n,P):
    cnt = 0
    for i in range(n):
        time = freq[i]
        mul = 2
        while(time<=mid):
            cnt+=1
            time += (freq[i]*mul)
            mul+=1
        
        if(cnt >= P): return True
    
    return False


def main():
    t = int(input())

    while(t):
        P = int(input())
        n_and_vals = input().split(" ")
        n = int(n_and_vals[0])
        freq = [int(n_and_vals[i]) for i in range(1,len(n_and_vals))]

        s = 0
        e = 1_000_000_000

        while(s<=e):
            mid = s + (e-s)//2

            if(possible(freq,mid,n,P)):
                ans = mid
                e = mid-1

            else:
                s = mid+1
        print(ans)
        t-=1
        

if(__name__ == "__main__"):
    main()