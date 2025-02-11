//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &prof) {

        int n = id.size();
        vector<Job> v(n);
        
        for(int i = 0;i<n;i++) {
            v[i] = {id[i],deadline[i],prof[i]};
        }
        
        sort(begin(v),end(v),cmp);
        
        int jobsDone = 0;
        int profit = 0;
        
        
        
        vector<int> jobs(n+1,0);
        
        for(int i = 0;i<n;i++) {
            if(jobs[v[i].deadline] == 0) {
                profit += v[i].profit;
                jobsDone++;
                jobs[v[i].deadline] = 1;
            }
            else {
                int j = v[i].deadline;
                while(j > 0 && jobs[j] != 0) j--;
                
                if(j == 0) continue;
                
                jobs[j] = 1;
                profit += v[i].profit;
                jobsDone++;
            }
        }
        
        return {jobsDone,profit};
        
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends