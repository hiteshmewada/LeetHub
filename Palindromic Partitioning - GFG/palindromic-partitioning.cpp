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
    int dp[501];
    int partition(int st, int end, string str){
        if(st==end) return 0;
        int cost=0;
        string temp;
        if(dp[st]!=-1) return dp[st];
        int mnCost=INT_MAX;
        for(int part=st;part<end;part++){
            temp+=str[part];
            if(palin(temp)){
                if(part!=(end-1))
                cost=1+partition(part+1,end,str);
            }
            mnCost=min(mnCost,cost);
        }
        if(palin(temp)) return dp[st]=0;
        return dp[st]=mnCost;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return partition(0,str.size(),str);
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