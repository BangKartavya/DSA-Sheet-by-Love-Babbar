from typing import List

class Node:
    def __init__(self,x):
        self.data = x
        self.left = None
        self.right = None
        

class Solution:
    
    def insert(self,root,val):
        if(not root):
            return Node(val)
        
        if(val >= root.data):
            root.right = self.insert(root.right,val)
        
        else:
            self.suc = root.data
            root.left = self.insert(root.left,val)
        
        return root
        
    def findLeastGreater(self, n : int, arr : List[int]) -> List[int]:
        
        root = None
        result = [0]*n
        
        for i in range(n-1,-1,-1):
            self.suc = -1
            root = self.insert(root,arr[i])
            result[i] = self.suc

        return result

#{ 
 # Driver Code Starts


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
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.findLeastGreater(n, arr)
        
        IntArray().Print(res)
        

        print("~")
# } Driver Code Ends