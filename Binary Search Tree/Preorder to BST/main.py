#User function Template for python3

class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None

#Function that constructs BST from its preorder traversal.
def buildTree(pre,i,size,upperBound):
    if(i[0] >= size or pre[i[0]] > upperBound): return None
    
    root = Node(pre[i[0]])
    i[0]+=1
    root.left = buildTree(pre,i,size,root.data)
    root.right = buildTree(pre,i,size,upperBound)
    
    return root
    
def Bst(pre, size) -> Node:
    i = [0]
    
    return buildTree(pre,i,size,10**9)
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3


#contributed by RavinderSinghPB
class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None


def postOrd(root):
    if not root:
        return
    postOrd(root.left)
    postOrd(root.right)
    print(root.data, end=' ')


if __name__ == '__main__':
    t = int(input())

    for _tcs in range(t):
        size = int(input())
        pre = [int(x) for x in input().split()]

        root = Bst(pre, size)

        postOrd(root)
        print()

        print("~")
# } Driver Code Ends