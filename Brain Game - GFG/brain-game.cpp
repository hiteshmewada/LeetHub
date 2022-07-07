// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	/*
	    Case 1: if all are prime a lose
	    case 2: if any one non prime with one factor B lose
	    Case 3 if(count of one non prime and count of second non prime are equal
	                then A loses as they both cancel out)
	   else B loses
	*/
	bool prime[1001];
	void solve(){
	    memset(prime,true,sizeof(prime));
	    int n=1001;
	    for(int i=2;i*i<=n;i++){
	        if(prime[i]){
	            for(int j=i*i;j<n;j+=i) prime[j]=false;
	        }
	    }
	}
	int count(int a){
	    int c=0;
                while(a%2==0){
                    a/=2;c++;
                }
                for(int j=3;j<=sqrt(a);j+=2){
                    while(a%j==0 ){
                        c++;a/=j;
                    }
                    
                }
                if(a>2) c++;
        return c;
	}
    bool brainGame(vector<int>nums) {
        // Code here.
        solve();
        int n=nums.size(),b=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int a=nums[i];
            if(prime[a]) continue;
            else{
            
                
                ans[i]=count(a)-1;
            }
            
        }
        int res=0;
        for(auto x:ans) res^=x;
        if(res) return true;
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends