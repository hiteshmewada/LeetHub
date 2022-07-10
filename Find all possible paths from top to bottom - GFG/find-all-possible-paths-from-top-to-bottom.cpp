// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
vector<vector<int>>ans;
void rec(int n, int m, int i, int j,vector<int>&v, vector<vector<int>> &grid)
    {
        if(i>=n or j>=m) return ;
        if(i==(n-1) and j==(m-1)){
            v.push_back(grid[i][j]);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(grid[i][j]);
        rec(n,m,i+1,j,v,grid);
        v.pop_back();
        v.push_back(grid[i][j]);
        rec(n,m,i,j+1,v,grid);
        v.pop_back();
        return;
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<int>v;
        rec(n,m,0,0,v,grid);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends