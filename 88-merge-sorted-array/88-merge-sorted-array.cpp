class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int i=m-1,j=n-1,ind=(n+m)-1;
        while(j>=0){
            v1[ind--]=i>=0 and v1[i]>v2[j]?v1[i--]:v2[j--];
        }
//         while(i>=m and j>=n){
//             if(v1[i]>v2[j]) {
//                 v1[ind--]=v1[i--];
//             }
//             else v1[ind--]=v2[j--];
//         }
        
    }
};