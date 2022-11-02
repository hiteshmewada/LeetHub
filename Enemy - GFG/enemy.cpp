//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            unordered_set<int>row,col;
            for(auto x:enemy){
                row.insert(x[0]);
                col.insert(x[1]);
            }
            int mxr=0,cnt=0;
            for(int i=1;i<=n;i++){
                if(row.find(i)==row.end()) cnt++;
                else{
                    mxr=max(mxr,cnt);
                    cnt=0;
                }
            }
            mxr=max(mxr,cnt);
            cnt=0;
            int mxc=0;
            for(int i=1;i<=m;i++){
                if(col.find(i)==col.end()) cnt++;
                else{
                    mxc=max(mxc,cnt);
                    cnt=0;
                }
            }
            mxc=max(mxc,cnt);
            return mxr*mxc;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends