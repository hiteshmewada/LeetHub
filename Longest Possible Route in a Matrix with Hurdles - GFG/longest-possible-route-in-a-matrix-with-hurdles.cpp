// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys]==0||matrix[xd][yd]==0)
       return -1;
       int n=matrix.size();
       int m=matrix[0].size();
       vector<vector<bool>> visited(n,vector<bool> (m,false));
       
       int count=helper(matrix,xs,ys,xd,yd,visited);
       if(count==INT_MIN)
       return -1;
       return count;
       
    }
    int helper(vector<vector<int>> matrix,int xs, int ys, int xd, int yd,vector<vector<bool>>& visited)
   {
       int n=matrix.size();
       int m=matrix[0].size();
       visited[xs][ys]=true;
       if(xs==xd&&ys==yd)
       {
           visited[xs][ys]=false;
       return 0;}
       int a=INT_MIN;
       int b=INT_MIN;
       int c=INT_MIN;
       int d=INT_MIN;
       if(xs+1<n&&matrix[xs+1][ys]==1&&visited[xs+1][ys]==false)
       a=helper(matrix,xs+1,ys,xd,yd,visited);
       if(a!=INT_MIN)
       a++;
       
       if(xs-1>=0&&matrix[xs-1][ys]==1&&visited[xs-1][ys]==false)
       b=helper(matrix,xs-1,ys,xd,yd,visited);
       if(b!=INT_MIN)
       b++;
       
       
       if(ys+1<m&&matrix[xs][ys+1]==1&&visited[xs][ys+1]==false)
       c=helper(matrix,xs,ys+1,xd,yd,visited);
       if(c!=INT_MIN)
       c++;
       
       if(ys-1>=0&&matrix[xs][ys-1]==1&&visited[xs][ys-1]==false)
       d=helper(matrix,xs,ys-1,xd,yd,visited);
       if(d!=INT_MIN)
       d++;
       
       visited[xs][ys]=false;
       
     return max(max(a,b),max(c,d));
       
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends