#User function Template for python3

'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:
    def merge(self, head, s , mid, e):
        n1 = mid-s+1
        n2 = e-mid
        
        L = []
        R = []
        
        cnt = 0
        temp = head
        temp2 = None
        
        while(cnt < s):
            temp = temp.next
            cnt+=1
        
        temp2 = temp
        
        for i in range(n1):
            L.append(temp.data)
            temp = temp.next
        
        cnt = 0
        temp = head
        
        while(cnt <= mid):
            temp = temp.next
            cnt+=1
        
        for i in range(n2):
            R.append(temp.data)
            temp = temp.next
        
    
        i = 0
        j = 0
        cnt = 0
        temp = temp2

        while(i < n1 and j < n2):
            if(L[i] <= R[j]):
                temp.data = L[i]
                i+=1
                temp = temp.next
            else:
                temp.data = R[j]
                j+=1
                temp = temp.next
        
        while(i < n1):
            temp.data = L[i]
            i+=1
            temp = temp.next
        
        while(j < n2):
            temp.data = R[j]
            j+=1
            temp = temp.next
        
        return None
    
    def merger(self,head,s,e):
        if(s >= e): return None
        
        mid = s + (e-s)//2

        self.merger(head,s,mid)
        self.merger(head,mid+1,e)
        self.merge(head,s,mid,e)
        
    def mergeSort(self, head):
        
        e = 0
        
        temp = head
        while(temp):
            e += 1
            temp = temp.next
        
        self.merger(head,0,e-1)
        
        return head
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        head = None
        if arr:
            head = Node(arr[0])
            tail = head
            for value in arr[1:]:
                tail.next = Node(value)
                tail = tail.next

        printList(Solution().mergeSort(head))
        print("~")
# } Driver Code Ends