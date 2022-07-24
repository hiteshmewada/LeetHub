class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            int k=0;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]==strs[0][i]) k++;
                else return ans;
            }
            if(k==strs.size()-1) ans+=strs[0][i];
        }
        return ans;
    }
};