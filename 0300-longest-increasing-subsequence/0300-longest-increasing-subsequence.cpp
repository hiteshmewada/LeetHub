class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0), cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int pre=i-1;pre>=-1;pre--){
                int len=next[pre+1];
                if(pre==-1 or nums[i]>nums[pre])
                    len=max(len,1+ next[i+1]);
                cur[pre+1]=len;
            }
            next=cur;
        }
        return next[0];
    }
};