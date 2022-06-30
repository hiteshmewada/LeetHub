class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot=nums[left];
        int l=left+1,r=right;
        while(l<=r){
            if(nums[l]<pivot and nums[r]>pivot) {
                swap(nums[l],nums[r]);
                l++;r--;
            }
            if(nums[l]>=pivot) l++;
            if(nums[r]<=pivot) r--;
        }
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size(),l=0,r=n-1;
        while(1){
            int pos=partition(nums,l,r);
            if(pos==k-1) return nums[pos];
            if(pos<k-1) l=pos+1;
            else r=pos-1;
        }
        return 0;
    }
};