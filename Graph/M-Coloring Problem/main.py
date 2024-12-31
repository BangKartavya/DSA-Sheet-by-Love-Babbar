# User function Template for python3

class Solution:
    def isPossible(self,node,col):
        for i in self.adj[node]:
            if(self.col[i] == col):
                return False
        
        return True
    
    def helper(self,node):
        if(node == self.v): return True
        
        for i in range(1,self.m+1):
            if(self.isPossible(node,i)):
                self.col[node] = i
                if(self.helper(node+1)): return True
                self.col[node] = 0
        
        return False
        
    def graphColoring(self, v, edges, m):
        self.adj = []
        self.vis = [False] * v
        self.col = [0] * v
        self.m = m
        self.v = v
        
        for i in range(v):
            self.adj.append([])
            
        for i in edges:
            self.adj[i[0]].append(i[1])
            self.adj[i[1]].append(i[0])
        
        if(self.helper(0)): return True
        
        return False
        

#{ 
 # Driver Code Starts
def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        edges_input = list(map(int, input().split()))
        m = int(input())
        edges = []

        # Populate the edges list with edge pairs
        for i in range(0, len(edges_input), 2):
            edges.append((edges_input[i], edges_input[i + 1]))

        solution = Solution()
        print("true" if solution.graphColoring(n, edges, m) else
              "false")  # Call the graph coloring function
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends