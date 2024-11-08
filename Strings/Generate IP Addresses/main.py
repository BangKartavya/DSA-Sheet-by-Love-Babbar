#Your Function should return a list containing all possible IP address
#No need to worry about order
class Solution:
    def check(self,s):
        n = len(s)
        
        if(n <= 0 or n>3): return False
        if(s[0] == '0' and n > 1): return False
        if(int(s) > 255): return False
        
        return True
    
    def gen(self,s,n,i,j,k):
        p1 = s[0:i]
        p2 = s[i:j]
        p3 = s[j:k]
        p4 = s[k:n]
        if(self.check(p1) and self.check(p2) and self.check(p3) and self.check(p4)): 
            return p1+'.'+p2+'.'+p3+'.'+p4
        
        return ""
        
    def genIp(self, s):
        n = len(s)
        ans = []
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    ip = self.gen(s,n,i,j,k)
                    if(ip != ''): ans.append(ip)
                    
        return ans

#{ 
 # Driver Code Starts
#Main
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        res = Solution().genIp(s)
        res.sort()
        if(len(res)):
            for u in res:
                print(u)
        else:
            print(-1)
        print("~")
# } Driver Code Ends 

