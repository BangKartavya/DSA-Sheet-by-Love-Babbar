//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool cmp(long long int& a, long long int& b) {
    return abs(a) <= abs(b);
}

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        
        if(k == 0) {
            return accumulate(a,a+n,0);
        }
        
        int negs= 0;
        int zeros = 0;
        long long int sum = 0;
        
        for(int i = 0;i<n;i++) {
            if(a[i] < 0) negs++;
            if(a[i] == 0) zeros++;
            
            sum += abs(a[i]);
        }
        
        sort(a,a+n,cmp);
        
        if(k == negs) return sum;
        
        else if(k > negs) {
            if(zeros!= 0) {
                return sum;   
            }
            else if((k-negs)%2==0) {
                return sum;
            }
            else {
                return sum - 2*abs(a[0]);
            }
        }
        else {
            for(int i = n-1;i>=0;i--) {
                if(k == 0) {
                    for(int i = 0;i<n;i++) {
                        if(a[i] < 0) {
                            sum += 2 * a[i];
                        }
                    }
                    return sum;
                }
                if(a[i] < 0) {
                    a[i] = abs(a[i]);
                    k--;
                }
            }
        } 
        
        return -1;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     
cout << "~" << "\n";
}
	
	return 0;
}
// } Driver Code Ends