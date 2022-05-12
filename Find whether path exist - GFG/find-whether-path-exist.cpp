// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& v) 
    {
        //code here
        int n=v.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    q.push({i,j});
                    v[i][j]=0;
                }
            }
        }
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0],ny=y+dir[i][1];
                if(nx>=0 and nx<n and ny>=0 and ny<n and v[nx][ny]!=0){
                    if(v[nx][ny]==2) return true;
                    q.push({nx,ny});
                    v[nx][ny]=0;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends