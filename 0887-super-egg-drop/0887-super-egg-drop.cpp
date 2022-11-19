class Solution {
public:
    int dp[101][10005];
    int find(int e, int f){
        if(f==1 or e==1 or f==0) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int ans=1000000;
        int low=1,high=f;
        while(low<=high){
            int m=low+(high-low)/2;
            int brk=find(e-1,m-1);
            int save=find(e,f-m);
            int temp=max(brk,save)+1;
            ans=min(ans,temp);
//             since right is more than left and we need more in worst case 
            if(brk<save) low=m+1;
            else high=m-1;
        }
        
        return dp[e][f]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return find(k,n);
    }
};