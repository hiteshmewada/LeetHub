// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    // x,y+2 x,y-1 x+1,y x-1,y x+1,y+1 x-1 y-1 x+1 y-1 x-1 y+1
	public:
	
	double helper(int x,int y, int k,int n,vector<vector<vector<double>>>&dp){
	   // cout<<1<<endl;
	    if(x<0 or y<0 or x>=n or y>=n) return 0;
	   // cout<<1<<endl;
	    double cnt=0;
	    
	   // cout<<dp[x][y][k]<<" ";
	    if(dp[x][y][k]!=-1) {
	        return dp[x][y][k];
	    }
	   // cout<<1<<endl;
	    if(k==0) {
	        return 1;
	    }
	   // cout<<1<<endl;
	    cnt+=helper(x-1,y-2,k-1,n,dp);
	   // cout<<k<<" "<<cnt;
	     cnt+=helper(x-1,y+2,k-1,n,dp);
	      cnt+=helper(x+1,y-2,k-1,n,dp);
	       cnt+=helper(x+1,y+2,k-1,n,dp); 
	       cnt+=helper(x-2,y-1,k-1,n,dp);
	        cnt+=helper(x-2,y+1,k-1,n,dp);
	         cnt+=helper(x+2,y-1,k-1,n,dp);
	          cnt+=helper(x+2,y+1,k-1,n,dp);
	          
	         return dp[x][y][k]=cnt;
	}
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // Code here
	    vector<vector<vector<double>>>dp(N,vector<vector<double>>
	    (N,vector<double>(steps+1,-1)));
	    double cnt=helper(start_x,start_y,steps,N,dp);
	    
	    double temp=pow(8,steps);
	   //cout<<temp<<" "<<cnt<<" ";
	   double ans=cnt/temp;
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends