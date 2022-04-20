// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    vector<pair<long long,long long>>v;
	    for(int i=0;i<N;i++){
	        if(ceil(sqrt(w[i]))!=floor(sqrt(w[i]))) v.push_back({p[i],w[i]});

	    }
	    sort(v.begin(),v.end(),[&](pair<long long,long long>&p1,
	        pair<long long,long long>&p2){
	       long double v1=(1.0*p1.first)/(1.0*p1.second);
	       long double v2=(1.0*p2.first)/(1.0*p2.second);
	       return v1>v2;
	    });
	    long double ans=0;
	    for(int i=0;i<v.size();i++){
	        if(C>=v[i].second){
	            ans+=v[i].first;
	            C-=v[i].second;
	        }
	        else{
	            long double x=(1.0*C*v[i].first)/(1.0*v[i].second);
	            ans+=x;
	            C=0;break;
	        }
	    }
	    return ans;
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends