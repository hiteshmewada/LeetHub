class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        dp[0]=nums[0];
        deque<int>q{0};
        for(int i=1;i<n;i++){
           if(q.front()<(i-k)) q.pop_front(); // can't reach current index from index stored in q   
            dp[i]=nums[i]+dp[q.front()];   //update max score for current index
            // pop indices which won't be ever chosen in the future
            while(!q.empty() and dp[q.back()]<=dp[i]) 
                    q.pop_back();
            q.push_back(i);
        }
        return dp.back();
    }
    
};