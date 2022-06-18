class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>pre(n),suf(n);
        for(int i=0;i<n;i++){
            pre[i]=(i==0)?h[i]:max(pre[i-1],h[i]);
        }
        for(int i=n-1;i>=0;i--){
            suf[i]=(i==n-1)?h[i]:max(suf[i+1],h[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int a=min(pre[i],suf[i])-h[i];
            if(a>=0) ans+=a;
        }
        return ans;
    }
};