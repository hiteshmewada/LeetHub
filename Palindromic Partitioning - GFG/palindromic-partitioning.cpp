//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool palin(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){i++;j--;}
            else return false;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int cost=0;
            string temp;
            int mnCost=INT_MAX;
            for(int part=i;part<n;part++){
                temp+=str[part];
                if(palin(temp)){
                    // if(part!=(n-1))
                    cost=1+dp[part+1];
                }
                mnCost=min(mnCost,cost);
            }
            if(palin(temp))  dp[i]=0;
             dp[i]=mnCost;
        }
        return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends