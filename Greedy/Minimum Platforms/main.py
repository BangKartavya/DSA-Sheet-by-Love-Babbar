#User function Template for python3

class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,arr,dep):
        max_dep: int = max(dep)
        n: int = len(arr)
        
        v: list[int] = [0]*(max_dep+2)
        
        for i in range(n):
            v[arr[i]]+=1
            v[dep[i]+1]-=1
        
        
        cnt: int = 0
        res: int = 0
        
        for i in v:
            cnt+=i
            res = max(res,cnt)
        
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.minimumPlatform(arrival, departure))
        print("~")

# } Driver Code Ends