#User function Template for python3
from heapq import heappop, heappush, heapify

class Solution :
    def rearrangeString(self, s):
        mp = {}
        n = len(s)
        for i in s:
            try:
                mp[i]+=1
            except KeyError:
                mp[i] = 1
        
        pq = []
        heapify(pq)
        
        for key,value in mp.items():
            if(value > (n+1)//2):
                return "-1"
            
            heappush(pq,[-1*value,key])
        res = "";
        while(len(pq) >= 2):
            a = heappop(pq)
            b = heappop(pq)
            
            res+=a[1]
            res+=b[1]
            
            a[0]+=1
            b[0]+=1
            
            if(a[0]<0): heappush(pq,a)
            if(b[0]<0): heappush(pq,b)
        
        
        if(len(pq) != 0):
            res+= heappop(pq)[1]
        
        return res
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        str1 = input()
        solObj = Solution()
        str2 = solObj.rearrangeString(str1)
        if str2=='-1':
            print(0)
        elif sorted(str1)!=sorted(str2):
            print(0)
        else:
            for i in range(len(str2)-1):
                if str2[i]==str2[i+1]:
                    print(0)
                    break
            else:
                print(1)
        
        print("~")
# } Driver Code Ends