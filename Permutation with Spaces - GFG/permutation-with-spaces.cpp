// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
vector<string>ans;
void helper(string s, int id, string  p){
    int n=s.size();
   if(id==n ) {
       ans.push_back(p);
       return;
   }
   if(id!=0) helper(s,id+1,p+" "+s[id]);
   helper(s,id+1,p+s[id]);
}
    vector<string> permutation(string S){
        // Code Here
        // ans.insert(S);
        string cur="";
        helper(S,0,cur);
        
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends