from typing import List


class Solution:
    def solve(self,line,station):
        if(station == self.n-1):
            return self.a[int(line)][station] + self.x[int(line)]
        
        if(self.dp[int(line)][station] != -1): return self.dp[int(line)][station]
        
        straight = self.a[int(line)][station] + self.solve(line,station+1)
        changeLine = self.a[int(line)][station] + self.T[int(line)][station+1] + self.solve(not line, station+1)
        
        self.dp[int(line)][station] = min(straight,changeLine)
        
        return self.dp[int(line)][station]
            
    def carAssembly(self, n : int, a : List[List[int]], T : List[List[int]], e : List[int], x : List[int]) -> int:
        self.n = n
        self.a = a
        self.T = T
        self.e = e
        self.x = x
        
        self.dp = [[-1 for i in range(n+1)] for i in range(2)]
        
        return min(self.solve(False,0) + e[0], self.solve(True,0) + e[1])
        



#{ 
 # Driver Code Starts
class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()



class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        a=IntMatrix().Input(2, 2)
        
        
        T=IntMatrix().Input(2, 2)
        
        
        e=IntArray().Input(2)
        
        
        x=IntArray().Input(2)
        
        obj = Solution()
        res = obj.carAssembly(n, a, T, e, x)
        
        print(res)
        

# } Driver Code Ends