# User function Template for python3

class Solution:
    # Function to find the next greater element for each element of the array.
    def nextLargerElement(self, arr):
        n = len(arr)
        stk = []
        result = [0] * n
        
        for i in range(n-1,-1,-1):
            if(len(stk) == 0):
                result[i] = -1
                stk.append(arr[i])
            else:
                while(len(stk) > 0 and arr[i] >= stk[-1]):
                    stk.pop()
                
                if(len(stk) == 0):
                    result[i] = -1
                else:
                    result[i] = stk[-1]
                
                stk.append(arr[i])

        return result

#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())  # number of test cases
for _ in range(t):
    arr = list(map(int, input().split()))  # input array
    s = Solution().nextLargerElement(arr)  # find the next greater elements

    # Output formatting
    if s:
        print(" ".join(map(str, s)))  # Print next greater elements
    else:
        print("[]")  # Print empty list if no next greater element is found
    print("~")
# } Driver Code Ends