#User function Template for python3

'''
# Node class
class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None

'''
# Note: Build tree and return root node
class Solution:
    def buildTree(self, inorder, preorder):
        if(not inorder or not preorder): return None
        
        root = Node(preorder[0])
        
        mid = inorder.index(root.data)
        
        root.left = self.buildTree(inorder[:mid],preorder[1:mid+1])
        root.right = self.buildTree(inorder[mid+1:],preorder[mid+1:])
        
        return root


#{ 
 # Driver Code Starts
#Initial Template for Python 3


class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        inorder = [int(x) for x in input().split()]
        preorder = [int(x) for x in input().split()]

        root = Solution().buildTree(inorder, preorder)
        printPostorder(root)
        print()

# } Driver Code Ends