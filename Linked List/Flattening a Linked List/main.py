#User function Template for python3


'''

class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None
        
'''

class Solution:
    def merge(self,h1,h2):
        if(not h1): return h2
        if(not h2): return h1
        
        head1 = h1
        head2 = h2
        
        head = Node(-1)
        temp = head
        
        while(head1 and head2):
            if(head1.data <= head2.data):
                temp.bottom = head1
                head1 = head1.bottom
            else:
                temp.bottom = head2
                head2 = head2.bottom
            temp = temp.bottom
        
        while(head1):
            temp.bottom = head1
            head1 = head1.bottom
            temp = temp.bottom
        
        while(head2):
            temp.bottom = head2
            head2 = head2.bottom
            temp = temp.bottom
        
        return head.bottom
        
    def flatten(self, root):
        if(not root or not root.next): return root
        
        root.next = self.flatten(root.next)
        
        return self.merge(root,root.next)



#{ 
 # Driver Code Starts
class Node:

    def __init__(self, d):
        self.data = d
        self.next = None
        self.bottom = None


def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.bottom
    print()


def createLinkedList(lists):
    head = None
    temp = None
    for list_head in lists:
        if head is None:
            head = list_head
            temp = head
        else:
            temp.next = list_head
            temp = temp.next
    return head


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        lists = []
        for _ in range(n):
            values = list(map(int, input().split()))
            head = None
            temp = None
            for value in values:
                newNode = Node(value)
                if head is None:
                    head = newNode
                    temp = head
                else:
                    temp.bottom = newNode
                    temp = temp.bottom
            lists.append(head)

        sol = Solution()
        linkedlist = createLinkedList(lists)
        head = sol.flatten(linkedlist)
        printList(head)
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends