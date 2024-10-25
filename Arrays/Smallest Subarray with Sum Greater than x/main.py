class Solution:
    def smallestSubWithSum(self, x, arr):
        n: int = len(arr)
        
        total: int = 0
        
        for i in arr:
            total += i
        
        if(total < x): return 0
        
        
        
        start: int = 0
        end: int = 0
        currSum: int = 0
        mini:int = n+1
        
        while(end < n):
            
            while(currSum <= x and end < n):
                currSum+=arr[end]
                end+=1
            
            while(currSum > x and start < end):
                mini = min(end-start,mini)
                currSum -= arr[start]
                start += 1
                
        
        return mini



#{ 
 # Driver Code Starts
def main():

    T = int(input())

    while (T > 0):
        x = int(input())
        a = [int(x) for x in input().strip().split()]
        print(Solution().smallestSubWithSum(x, a))

        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends