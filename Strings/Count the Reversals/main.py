def countRev (s):
    
    if(len(s)%2): return -1
    
    stk = []
    cnt=0
    
    for i in s:
        if(i == '{'): stk.append(i)
        else:
            if(len(stk)==0):
                cnt+=1
                stk.append('{')
            else:
                stk.pop()
        
    
    if(len(stk)==0): return cnt
    else:
        cnt += len(stk)//2
        return cnt


#{ 
 # Driver Code Starts
t = int (input ())
for tc in range (t):
    s = input ()
    print (countRev (s))

    print("~")
# Contributed By: Pranay Bansal

# } Driver Code Ends