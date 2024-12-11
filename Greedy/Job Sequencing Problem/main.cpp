//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
        int id;       // Job Id
        int deadline; // Deadline of job
        int profit;   // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

bool cmp(Job& a, Job& b) {
    return a.profit > b.profit;
}

class Solution {
    public:
        // Function to find the maximum profit and the number of jobs done.
        vector<int> JobScheduling(Job jobs[], int n) {
            sort(jobs, jobs + n, cmp);
            int profit = 0;
            int jobs_done = 0;

            int freq[n + 1];
            memset(freq, -1, sizeof(freq));

            for(int i = 0; i < n; i++) {
                if(freq[jobs[i].deadline] == -1) {
                    freq[jobs[i].deadline] = jobs[i].id;
                    profit += jobs[i].profit;
                    jobs_done++;
                } else {
                    int j = jobs[i].deadline;
                    while(j > 0 && freq[j] != -1) {
                        j--;
                    }
                    if(j == 0) continue;

                    else {
                        freq[j] = jobs[i].id;
                        profit += jobs[i].profit;
                        jobs_done++;
                    }
                }
            }
            return {jobs_done, profit};
        }
};

//{ Driver Code Starts.
//         Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while(ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while(ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while(ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();
        Job jobs[n];
        for(int i = 0; i < n; ++i) {
            jobs[i] = {jobIDs[i], deadlines[i], profits[i]};
        }

        Solution obj;
        vector<int> ans = obj.JobScheduling(jobs, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends