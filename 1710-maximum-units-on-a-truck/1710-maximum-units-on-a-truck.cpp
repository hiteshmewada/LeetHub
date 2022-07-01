class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // 2 2.5 1.7 3
        // 18+10+, 10+18+28+10, 50+18+14, 27+10+
        // 5 10 3 9 4 7 2 5
        // 50+27+14
        sort(boxTypes.begin(),boxTypes.end(),[&](const vector<int>a, const vector<int>b){
            return a[1]>b[1];
        });
        int ans=0;
        for(auto x:boxTypes){
            int y=min(x[0],truckSize);
            ans+=y*x[1];
            truckSize-=y;
        }
        return ans;
    }
};