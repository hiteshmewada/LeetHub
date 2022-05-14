// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&m){
    // Code here
    int n=m.size(),a=m[0].size();
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<a;j++){
            if(m[i][j]!=-1){
                m[i][j]+=max({j>0?m[i+1][j-1]:0,m[i+1][j],j+1<a?m[i+1][j+1]:0,0});
            }
        }
    }
    return max(0,*max_element(m[0].begin(),m[0].end()));
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends