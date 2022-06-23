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
    void f(vector<string>&v,int n,int col){
        if(col==n){
            ans.push_back(v);return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,v,n)){
                v[row][col]='Q';
                f(v,n,col+1);
                v[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n);
        string s(n,'.');
        for(int i=0;i<n;i++) v[i]=s;
        f(v,n,0);
        return ans;
    }
};