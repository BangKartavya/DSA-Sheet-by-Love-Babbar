#User function Template for python3

def pivot(arr,s,e):
    
    if(arr[s] <= arr[e]): return s
    
    mid = s + (e-s)//2
    
    if(arr[mid] > arr[e]): return pivot(arr,mid+1,e)
    
    if(arr[mid] < arr[s]): return pivot(arr,s,mid)

def search(arr,s,e,K):
    
    if(s > e): return -1
    
    mid = s + (e-s)//2
    
    if(arr[mid] == K): return mid
    elif(arr[mid] > K): return search(arr,s,mid-1,K)
    else: return search(arr,mid+1,e,K)
    

def Search(arr,n,K):
    piv = pivot(arr,0,n-1)
    
    if(piv == -1): return search(arr,0,n-1,K)
    else:
        s1 = search(arr,0,piv,K)
        s2 = search(arr,piv+1,n-1,K)
        
        if(s1 == -1): return s2
        if(s2 == -1): return s1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tcs=int(input())
    for _ in range(tcs):
        n=int(input())
        arr=[int(x) for x in input().split()]
        k=int(input())

        print(Search(arr,n,k))

        print("~")
# } Driver Code Ends