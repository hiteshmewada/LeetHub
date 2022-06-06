class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,can=0;
        for(auto x:nums){
            if(cnt==0) can=x;
            if(x==can) cnt++;
            else cnt--;
        }
        return can;
    }
};