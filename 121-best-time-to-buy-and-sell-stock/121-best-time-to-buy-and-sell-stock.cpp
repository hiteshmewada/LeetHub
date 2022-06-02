class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ar[n];
        ar[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            ar[i]=max(ar[i+1],prices[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(ar[i+1]>prices[i]){
                ans=max(ans,ar[i+1]-prices[i]);
            }
        }
        return ans;
    }
};