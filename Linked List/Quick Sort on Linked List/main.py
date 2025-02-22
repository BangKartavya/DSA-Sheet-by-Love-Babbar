# User function Template for python3


def quickSort(head):
    if not head or not head.next:
        return head
    temp = head

    smallHead = Node(-1)
    largeHead = Node(-1)

    small = smallHead
    large = largeHead

    curr = head.next
    pivot = head

    while curr:
        if curr.data < pivot.data:
            smallHead.next = curr
            smallHead = smallHead.next
        else:
            largeHead.next = curr
            largeHead = largeHead.next

        curr = curr.next

    smallHead.next = None
    largeHead.next = None

    small = quickSort(small.next)
    pivot.next = None
    large = quickSort(large.next)

    temp = small

    while temp and temp.next:
        temp = temp.next

    if temp:
        temp.next = pivot
    else:
        small = pivot

    pivot.next = large
    return small


# {
# Driver Code Starts
# Initial Template for Python 3

# contributed by RavinderSinghPB
from collections import defaultdict


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class Llist:

    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


def nodeID(head, dic):
    while head:
        dic[head.data].append(id(head))
        head = head.next


def printList(head, dic):
    while head:
        if id(head) not in dic[head.data]:
            print("Do'nt swap data, swap pointer/node")
            return
        print(head.data, end=" ")
        head = head.next


if __name__ == "__main__":
    t = int(input())

    for tcs in range(t):

        arr = [int(x) for x in input().split()]

        ll = Llist()
        tail = None

        for nodeData in arr:
            tail = ll.insert(nodeData, tail)

        dic = defaultdict(list)  # dictonary to keep data and id of node
        nodeID(ll.head, dic)  # putting data and its id

        resHead = quickSort(ll.head)
        printList(resHead, dic)  # verifying and printing
        print()

        print("~")

# } Driver Code Ends
