#User function Template for python3
class Solution:
    def dfs(self,node: int, adj, dia: int):
        for it in adj[node]:
            dia = min(dia,it[1])
            return self.dfs(it[0],adj,dia)
        
        return [node,dia]
        
    def solve(self, n, p ,a, b, d): 
        adj = [[] for i in range(n+1)]
        indegree: list[int] = [0]*(n+1)
        outdegree: list[int] = [0]*(n+1)
        
        
        for i in range(p):
            adj[a[i]].append([b[i],d[i]])
            indegree[b[i]]+=1
            outdegree[a[i]]+=1
        
        ans: list[list[int]] = []
        
        for i in range(1,n+1):
            if(indegree[i] == 0 and outdegree[i] > 0):
                end = self.dfs(i,adj,50000)[0]
                dia = self.dfs(i,adj,50000)[1]
                
                ans.append([i,end,dia])

        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        
        n,p = map(int,input().strip().split())
        a = []
        b = []
        d = []
        for i in range(p):
            x,y,z = map(int,input().strip().split())
            a.append(x)
            b.append(y)
            d.append(z)
            
        ob = Solution()
        ans = ob.solve(n, p, a, b, d)
        print(len(ans))
        for i in ans:
            print(str(i[0])+" "+str(i[1])+" "+str(i[2]))


# } Driver Code Ends