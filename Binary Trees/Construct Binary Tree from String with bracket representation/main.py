from typing import Optional
from collections import deque
"""

definition of binary tree node.
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
"""

class Solution:
    def solve(self,root):
        if(self.i < self.n and self.s[self.i].isdigit()):
            num = 0
            while(self.i < self.n and self.s[self.i].isdigit()):
                num*=10
                num += int(self.s[self.i])
                self.i+=1
            
            root.data = num
        
        if(self.i < self.n and self.s[self.i] == '('):
            self.i+=1
            root.left = Node(float("-inf"))
            self.solve(root.left)
            
            if(root.left.data == float("-inf")): root.left = None
        
        
        if(self.i < self.n and self.s[self.i] == '('):
            self.i+=1
            root.right = Node(float("-inf"))
            self.solve(root.right)
            
            if(root.right.data == float("-inf")): root.right = None
        
        if(self.i >= self.n or self.s[self.i] == ')'):
            self.i+=1
            return
        
            
    def treeFromString(self, s : str) -> Optional['Node']:
        root = Node(float("-inf"))
        self.i = 0
        self.s = s
        self.n = len(s)
        self.solve(root)
        
        return root
        



#{ 
 # Driver Code Starts
class Node:
    def __init__(self,val):
        self.data=val
        self.right=None
        self.left=None

# Function to Build Tree
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root

def inputTree():
    treeString=input().strip()
    root = buildTree(treeString)
    return root
def inorder(root):
    if (root == None):
       return
    inorder(root.left);
    print(root.data,end=" ")
    inorder(root.right)

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        s = (input())
        
        obj = Solution()
        res = obj.treeFromString(s)
        
        inorder(res)
        print()
        

        print("~")
# } Driver Code Ends