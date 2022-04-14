class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        int n=mat.size(),m=mat[0].size();
        int row[n],col[m];
        for(int i=0;i<n;i++) row[i]=0;
        for(int i=0;i<m;i++) col[i]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]++;
                    col[j]++;
                }
                
            }
        }
        for(int i=0;i<n;i++){
            if(row[i]){
                for(int j=0;j<m;j++) mat[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(col[i]){
                for(int j=0;j<n;j++) mat[j][i]=0;
            }
        }
    }
};