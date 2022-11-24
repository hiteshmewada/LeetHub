//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    int wordBreak(string A, vector<string> &B) {
        
        vector<bool>dp(A.size()+1,false);
        unordered_set<string>st;
        for(auto x:B) st.insert(x);
        int n=A.size();
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            string s="";
            bool flag=0;
            for(int k=i;k<n;k++){
                s+=A[k];
                if(st.find(s)!=st.end() and dp[k+1]==true) 
                   {
                       flag=1;
                        dp[i]=true;
                   }
            }
            if(!flag)
            dp[i]=false;
        }
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends