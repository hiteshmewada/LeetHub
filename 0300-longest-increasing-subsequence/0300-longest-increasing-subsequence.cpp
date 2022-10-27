class Solution {
public:
    void bs(vector<int>&temp, int val){
        int n=temp.size();
        int l=0,h=n;
        while(l<h){
            int md=l+(h-l)/2;
            if(temp[md]<val) l=md+1;
            else h=md;
        }
        temp[h]=val;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(auto x:nums){
            if(x>temp.back()) temp.push_back(x);
            else{
                bs(temp,x);
            }
        }
        return temp.size();
    }
};