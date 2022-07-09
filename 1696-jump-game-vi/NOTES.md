dp[0]=nums[0];
for(int i=1;i<n;i++){
for(int j=1;j<=k and (i-j)>=0 ; j++){
dp[i]=max(dp[i],(dp[i-j]+nums[i]));
}
}
return dp.back();
}
};
​
Solution - IV (Optimized Dynamic Programming)
​
class Solution {
public:
int maxResult(vector<int>& nums, int k) {
int n=nums.size();
vector<int>dp(n,INT_MIN);
multiset<int>s({dp[0]=nums[0]});
for(int i=1;i<n;i++){
if(i>k) s.erase(s.find(dp[i-k-1]));
s.insert(dp[i]=*rbegin(s)+nums[i]);
}
return dp.back();
}
};
​
Time Complexity : O(N*log(k))
Space Complexity : O(N)
​
​
​