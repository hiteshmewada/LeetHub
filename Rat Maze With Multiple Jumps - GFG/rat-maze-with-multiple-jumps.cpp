// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
set<pair<int,int>>p;
    bool start(int r,int c,vector<vector<int>>&m,int n,vector<vector<int>>&ans){
        ans[r][c]=1;
        if(r==n-1 and c==n-1) return true;
        for(int jump=1;jump<=m[r][c];jump++){
            if(c+jump<n and start(r,c+jump,m,n,ans)) return true;
            if(r+jump<n and start(r+jump,c,m,n,ans)) return true;
        }
        ans[r][c]=0;
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&m){
	   // Code here
	       int n=m.size();
	   vector<vector<int>>ans(n,vector<int>(n));
	   if(start(0,0,m,n,ans)){
	       return ans;
	   }
	   else return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends