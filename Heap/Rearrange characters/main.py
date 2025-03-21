from heapq import heappush, heappop

class Solution :
    def rearrangeString(self, s):
        pq = []
        result = ""
        freq = [0]*26
        
        for ch in s:
            freq[ord(ch)-ord('a')]+=1
        
        for i in range(26):
            if(freq[i] > (len(s)+1)//2): return ""
            if(freq[i] == 0): continue
            heappush(pq,[-freq[i],chr(i+ord('a'))])

        
        while(len(pq) >= 2):
            a = pq[0]
            heappop(pq)
            b = pq[0]
            heappop(pq)
            
            result += a[1]
            result += b[1]
            
            a[0]+=1
            b[0]+=1
            
            if(a[0] < 0):
                heappush(pq,a)
            if(b[0] < 0):
                heappush(pq,b)
        
        if(len(pq) != 0):
            if(pq[0][0] != -1): return ""
            
            result += pq[0][1]
            heappop(pq)

        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        str1 = input()
        solObj = Solution()
        str2 = solObj.rearrangeString(str1)
        if str2 == '':
            print(0)
        elif sorted(str1) != sorted(str2):
            print(0)
        else:
            for i in range(len(str2) - 1):
                if str2[i] == str2[i + 1]:
                    print(0)
                    break
            else:
                print(1)

        print("~")

# } Driver Code Ends