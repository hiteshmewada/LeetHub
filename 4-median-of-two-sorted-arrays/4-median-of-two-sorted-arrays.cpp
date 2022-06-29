class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) swap(nums1,nums2);
        int n=nums1.size(),m=nums2.size();
        int tot=(n+m+1)/2;
        int l=0,h=m;
        while(l<=h){
            int mid1=l+(h-l)/2;
            int mid2=tot-mid1;
            int l1=mid1==0?INT_MIN:nums2[mid1-1];
            int r1=mid1==m?INT_MAX:nums2[mid1];
            int l2=mid2==0?INT_MIN:nums1[mid2-1];
            int r2=mid2==n?INT_MAX:nums1[mid2];
            if(l1<=r2 and l2<=r1){
                if((n+m)%2) return max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) h=mid1-1;
            else l=mid1+1;
        }
        return 0.0;
    }
};