#User function Template for python3

def smallerThan(mat,x):
    ans: int = 0
    
    for i in mat:
        low: int = 0
        high: int = len(i)-1
        temp: int = len(i)
        while(low <= high):
            mid: int = low + (high-low)//2
            
            if(i[mid] > x):
                temp = mid
                high = mid-1
            else:
                low = mid+1
        ans+=temp
    return ans

def kthSmallest(mat, n, k): 
    low: int = mat[0][0]
    high: int = mat[n-1][n-1]
    
    while(low <= high):
        mid: int = low + (high - low)//2
        smal: int = smallerThan(mat,mid)
        if(smal <= k-1): low = mid+1
        elif(smal > k-1): high = mid-1
    
    return low




#{ 
 # Driver Code Starts
#Initial Template for Python 3

# Driver Code 

def main():
    T=int(input())
    while(T>0):
        n = int(input())
        mat=[[0 for j in range(n)] for i in range(n)]
        line1=[int(x) for x in input().strip().split()]
        k = int(input())

        temp=0
        for i in range(n):
            for j in range (n):
                mat[i][j]=line1[temp]
                temp+=1
        
        print(kthSmallest(mat, n, k))
        T-=1


        print("~")
if __name__=="__main__":
    main()




# } Driver Code Ends