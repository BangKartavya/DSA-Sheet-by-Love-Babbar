#User function Template for python3

class Solution:
    
    #Function to check whether there is a subarray present with 0-sum or not.
    def subArrayExists(self,arr):
        mp:dict[int,int] = {}
        n: int = len(arr)
        sumi: int = 0
        
        for i in range(n):
            if(sumi + arr[i] == 0): return True
            else:
                sumi += arr[i]
                try:
                    mp[sumi]
                    return True
                except KeyError:
                    mp[sumi] = i
    
        return False

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]
        if (Solution().subArrayExists(arr)):
            print("true")
        else:
            print("false")

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends