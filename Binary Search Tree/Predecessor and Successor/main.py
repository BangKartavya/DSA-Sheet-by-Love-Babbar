'''
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
'''


# This function finds predecessor and successor of key in BST.
# It sets pre and suc as predecessor and successor respectively
class Solution:
    def __init__(self):
        self.suc = Node(None)
        self.pre = Node(None)
        
    def findSuccessor(self,root,key):
        if(not root): return
    
        if(key < root.key):
            self.suc = root
            self.findSuccessor(root.left,key)
        else:
            self.findSuccessor(root.right,key)
    
    def findPredecessor(self,root,key):
        if(not root): return
    
        if(key > root.key):
            self.pre = root
            
            self.findPredecessor(root.right,key)
        
        else:
            self.findPredecessor(root.left,key)
    
    def findPreSuc(self, root, pre, suc, key):
        self.findSuccessor(root,key)
        self.findPredecessor(root,key)
        
        pre.key = self.pre.key
        suc.key = self.suc.key


#{ 
 # Driver Code Starts
import queue


# BST Node
class Node:

    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def buildTree(ip):
    # Corner Case
    if len(ip) == 0 or ip[0] == 'N':
        return None

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    q = queue.Queue()
    q.put(root)

    # Starting from the second element
    i = 1
    while not q.empty() and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.get()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.right)

        i += 1
    return root


# Driver program to test above functions
t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s.split())
    k = int(input())
    pre = Node(None)
    succ = Node(None)
    ob = Solution()
    ob.findPreSuc(root, pre, succ, k)
    if pre.key:
        print(pre.key, end=' ')
    else:
        print(-1, end=' ')
    if succ.key:
        print(succ.key, end=' ')
    else:
        print(-1, end=' ')
    print()
    print("~")

# } Driver Code Ends