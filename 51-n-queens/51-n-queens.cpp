class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int r,int c,vector<string>v,int n){
        // check safety in backend from where u have already came
        int fr=r,fc=c;
        while(r>=0 and c>=0)
        {
            if(v[r][c]=='Q') return false;
            r--;c--;
        }
        r=fr,c=fc;
        while(c>=0){
            if(v[r][c]=='Q') return false;
            c--;
        }
        r=fr,c=fc;
        while(r<n and c>=0){
            if(v[r][c]=='Q') return false;
            c--;
            r++;
        }
        return true;
    }
    void f(vector<string>&v,int n,int col,vector<int>&leftRow,vector<int>&lowerDiagonal,vector<int>&upperDiagonal){
        if(col==n){
            ans.push_back(v);return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[n-1+row-col]==0){
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+row-col]=1;
                v[row][col]='Q';
                f(v,n,col+1,leftRow,lowerDiagonal,upperDiagonal);
                v[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+row-col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n);
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++) v[i]=s;
        f(v,n,0,leftRow,lowerDiagonal,upperDiagonal);
        return ans;
    }
};