class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=2;i<=n;i++){
            int n=ans.size();
            string temp;
            for(int i=0;i<n;i++){
                int cnt=1;
                while(i+1<n and ans[i]==ans[i+1]){
                    i++;cnt++;
                }
                temp+=(cnt+'0');
                temp+=ans[i];
            }
            ans=temp;
        }
        return ans;
    }
};