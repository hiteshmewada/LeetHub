class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0,i=0;
        vector<int>ans;
        while(i<m and j<n){
            if(nums1[i]<nums2[j]) {
                ans.push_back(nums1[i]);i++;
            }
            else{
                ans.push_back(nums2[j]);j++;
            }
        }
        while(i<m) {
            ans.push_back(nums1[i]);i++;
        }
        while(j<n) {
            ans.push_back(nums2[j]);j++;
        }
        nums1=ans;
//         for(int i=0;i<nums1.size();i++){
//             if(nums1[i]>=nums2[j]){
                
//             }
//         }
    }
};