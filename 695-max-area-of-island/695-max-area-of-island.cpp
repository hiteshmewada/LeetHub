class Solution {
public:
    vector<vector<int>>grid;
    vector<vector<bool>>vis;
    int area(int r, int c){
        if(r<0 or r>=grid.size() or c<0 or c>=grid[0].size() or vis[r][c]==true or grid[r][c]==0) return 0;
        vis[r][c]=true;
        return (1+area(r+1,c)+area(r-1,c)+area(r,c+1)+area(r,c-1));
    }
    int maxAreaOfIsland(vector<vector<int>>& gri) {
        grid=gri;
        int n=grid.size(),a=grid[0].size();
        vis.resize(n,{false});
        for(int i=0;i<n;i++) vis[i].resize(a,{false});
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<a;c++){
                ans=max(ans,area(r,c));
            }
        }
        return ans;
    }
};