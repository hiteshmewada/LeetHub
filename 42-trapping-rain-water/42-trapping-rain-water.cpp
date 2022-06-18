class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(),ans=0;
        int leftMax=0,rightMax=0,l=0,r=n-1;
        while(l<=r){
            if(h[l]<=h[r]){
                if(h[l]<leftMax) ans+=leftMax-h[l];
                else leftMax=h[l];
                l++;
            }
            else{
                if(h[r]<rightMax) ans+=rightMax-h[r];
                else rightMax=h[r];
                r--;
            }
        }
        return ans;
    }
};