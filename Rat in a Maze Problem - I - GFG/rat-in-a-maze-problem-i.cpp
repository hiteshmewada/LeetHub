// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>res;
    void solve(vector<vector<int>> &m, int n,string s, int i,int j,
    vector<vector<int>>&vis){
        if(i==n-1 and j==n-1){
            res.push_back(s);
            return;
        }
        // downward
        if(i+1<n and !vis[i+1][j] and m[i+1][j]==1){
            vis[i][j]=1;
            solve(m,n,s+'D',i+1,j,vis);
            vis[i][j]=0;
        }
        
        // leftward
        if(j-1>=0 and !vis[i][j-1] and m[i][j-1]==1){
            vis[i][j]=1;
            solve(m,n,s+'L',i,j-1,vis);
            vis[i][j]=0;
        }
        // rightward
        if(j+1<n and !vis[i][j+1] and m[i][j+1]==1){
            vis[i][j]=1;
            solve(m,n,s+'R',i,j+1,vis);
            vis[i][j]=0;
        }
        // upward
        if(i-1>=0 and !vis[i-1][j] and m[i-1][j]==1){
            vis[i][j]=1;
            solve(m,n,s+'U',i-1,j,vis);
            vis[i][j]=0;
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        string s="";
         if(m[0][0]==1) solve(m,n,s,0,0,vis);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends