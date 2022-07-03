// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string>ans;
    void solve(int n, vector<string>& dict, string s,int ind, string temp){
        if(ind>=s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<=s.size()-ind;i++){
            string p=s.substr(ind,i);
            for(auto x:dict){
                if(x==p){
                    // cout<<p<<" "<<i<<endl;
                    solve(n,dict,s,ind+i,temp+p+" ");
                    
                }
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        solve(n,dict,s,0,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends