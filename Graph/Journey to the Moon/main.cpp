#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    for(auto i : astronaut) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    long long int ans = 0;

    vector<long long int> v;
    queue<int> q;
    int singles = 0;

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;

        vis[i] = true;

        q.push(i);
        int num = 1;

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto it : adj[top]) {
                if(!vis[it]) {
                    num++;
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        if(num == 1) singles++;
        else v.push_back(num);
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            ans = (ans + (v[i] * v[j]));
        }
        ans = (ans + ((long long)singles * (long long)v[i]));
    }

    ans = (ans + ((long long)singles * (long long)(singles - 1) / (long long)2));

    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for(int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for(int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
