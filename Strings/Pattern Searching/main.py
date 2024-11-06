#User function Template for python3

def searchPattern(st, pat):
    badChar = [-1 for i in range(255)]
    
    n = len(st)
    m = len(pat)
    
    for i in range(m):
        badChar[ord(pat[i])] = i

    s = 0
    
    while(s <= n-m):
        j = m-1
        
        while(j >= 0 and st[s+j] == pat[j]): j-=1
        if(j < 0): return True
        
        else:
            if(badChar[ord(st[s+j])] == -1):
                s += j+1
            else:
                s += max(1,m-badChar[ord(st[s+j])]-1)
    
    return False

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t=int(input())
for i in range(t):
    st=input()
    pat=input()
    if (searchPattern(st, pat)):
        print("Present")
    else:
        print("Not present")
    print("~")
# } Driver Code Ends