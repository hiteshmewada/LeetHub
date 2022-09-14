class Solution {
public:
    void eraseByDfs(vector<vector<char>>& grid, int i, int j){
        int n=grid.size(),m=grid[0].size();
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0') return;
        grid[i][j]='0';
        eraseByDfs(grid, i+1,j);
        eraseByDfs(grid, i,j+1);
        eraseByDfs(grid, i,j-1);
        eraseByDfs(grid, i-1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>index={0,1,0,-1,0};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    eraseByDfs(grid, i,j);
                }
            }
        }
        return ans;
    }
};