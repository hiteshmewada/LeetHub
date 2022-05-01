// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string s, vector<vector<int>>q){
	    // Code 
	    vector<int>v[26];
	    for(int i=0;i<s.size();i++)
	        v[s[i]-'a'].push_back(i+1);
	   int j=0;
	   vector<int>ans;
	   while(j<q.size()){
	       int l=q[j][0],r=q[j][1],c=0;
	       for(int i=0;i<26;i++){
	           int x=lower_bound(v[i].begin(),v[i].end(),l)-v[i].begin();
	           if(x==v[i].size()) continue;
	           x=v[i][x];
	           if(x>=l and x<=r) c++;
	       }
	       ans.push_back(c);
	       j++;
	   }
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends