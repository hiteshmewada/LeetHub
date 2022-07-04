class Solution {
public:
    int candy(vector<int>& r) {
        int ans=0,n=r.size();
        vector<int>pre(n,0);
        pre[0]=1;
        for(int i=1;i<n;i++){
            if(r[i-1]<r[i]) pre[i]=pre[i-1]+1;
            else pre[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1]<r[i]) pre[i]=max(pre[i+1]+1,pre[i]);
        }
        for(auto x:pre) ans+=x;
        return ans;
    }
};