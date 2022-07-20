Brute Force
class Solution {
public:
int largestRectangleArea(vector<int>& h) {
int n=h.size();
int ans=INT_MIN;
for(int i=0;i<n;i++){
int minHeight=INT_MAX;
for(int j=i;j<n;j++){
minHeight=min(minHeight,h[j]);
ans=max(ans,(j-i+1)*minHeight);
}
}
return ans;
}
};