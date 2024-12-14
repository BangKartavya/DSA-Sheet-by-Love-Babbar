#User function Template for python3

class Solution:
    def pageFaults(self, N, C, pages):
        mem: list[int] = []
        faults: int = 0
        
        for page in pages:
            if(page in mem):
                idx: int = 0
                for i in range(len(mem)):
                    if(mem[i] == page):
                        idx = i
                        break
                mem = mem[0:idx] + mem[idx+1:]
                mem.append(page)
            else:
                faults+=1
                if(len(mem) < C):
                    mem.append(page)
                else:
                    mem = mem[1:]
                    mem.append(page)
                
        
        return faults


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        pages = input().split()
        for itr in range(N):
            pages[itr] = int(pages[itr])
        C = int(input())

        ob = Solution()
        print(ob.pageFaults(N, C, pages))

# } Driver Code Ends