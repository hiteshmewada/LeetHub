class Solution {
public:
    bool palin(string &v,int i,int j){
        // int i=0,j=v.size()-1;
        while(i<=j){
            if(v[i++]!=v[j--]) return false;
        }
        return true;
    }
    void f(string s,vector<string>&v, vector<vector<string>>&ans,int i,vector<vector<bool>> &dp){
        if(i==s.size()) {
                ans.push_back(v);
                // v.push_back(s[i]);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(s[i]==s[j] and ((j-i)<=1 or dp[i+1][j-1])){
                dp[i][j]=true;
                v.push_back(s.substr(i,j-i+1));
                f(s,v,ans,j+1,dp);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        vector<vector<string>>ans;
        f(s,v,ans,0,dp);
        return ans;
    }
};