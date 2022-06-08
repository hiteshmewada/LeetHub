class Solution {
public:
    int merge(vector<int>& nums,int l,int md,int h){
        int i=l,j=md+1,cnt=0;
        for(int k=l;k<=md;k++){
            while(j<=h and nums[k]>(2LL*nums[j])) j++;
            cnt+=(j-(md+1));
        }
        // vector<int>v[h];
        vector<int>v;
         j=md+1,i=l;
        while(i<=md and j<=h){
            if(nums[i]<nums[j]) v.push_back(nums[i++]);
            else v.push_back(nums[j++]);
        }
        while(i<=md) v.push_back(nums[i++]);
        while(j<=h) v.push_back(nums[j++]);
        for(int i=l;i<=h;i++) nums[i]=v[i-l];
        return cnt;
    }
    int mergeSort(vector<int>& nums,int l,int h){
        int cnt=0;
        if(l<h){
            int mid=l+(h-l)/2;
            cnt+=mergeSort(nums,l,mid);
            cnt+=mergeSort(nums,mid+1,h);
            cnt+=merge(nums,l,mid,h);
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};