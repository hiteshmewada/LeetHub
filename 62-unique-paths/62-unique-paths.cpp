class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans=1;
        int N=n+m-2;
        int r=n-1;
        for(int i=1;i<=r;i++){
            ans=(ans*(N-r+i))/i;
        }
        return (int)ans;
    }
};