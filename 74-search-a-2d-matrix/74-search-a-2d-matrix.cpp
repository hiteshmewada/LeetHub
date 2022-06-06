class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int lo=0,n=mat.size(),m=mat[0].size(),hi=m*n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int i=mid/m,j=mid%m;
            cout<<i<<" "<<j<<endl;
            int a=mat[i][j];
            cout<<mid<<" "<<a<<endl;
            if(t==a) return true;
            else if(t<a) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};