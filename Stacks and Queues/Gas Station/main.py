class Solution:
    def startStation(self, gas, cost):
        n = len(gas)
        currGas = 0
        totalGas = 0
        startIdx = 0
        
        for i in range(n):
            currGas += gas[i] - cost[i]
            totalGas += gas[i] - cost[i]
            
            if(currGas < 0):
                currGas = 0
                startIdx = i+1
                

        if(totalGas < 0): return -1
        
        return startIdx


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        gas = list(map(int, input().strip().split()))
        cost = list(map(int, input().strip().split()))
        ob = Solution()
        l = ob.startStation(gas, cost)
        print(l)
        print("~")

# } Driver Code Ends