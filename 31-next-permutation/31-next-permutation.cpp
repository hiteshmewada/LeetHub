class Solution {
public:
    /*
        1) First find decreasing element from right
        2) swap (a[i-1] with the number greater than a[i-1]);
        3) then reverse elements from a[i] to a[n-1];
    */
    void reversee(vector<int>&nums,int ind){
        int st=ind,end=nums.size()-1;
        while(st<end){
            swapp(nums[st],nums[end]);
            st++;
            end--;
        }
    }
    void swapp(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 and nums[i+1]<=nums[i]) i--;
        if(i>=0){
            int j=nums.size()-1;
            while(nums[j]<=nums[i]) j--;
            swapp(nums[i],nums[j]);
        }
        reversee(nums,i+1);
    }
};