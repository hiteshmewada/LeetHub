class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int n=grid.size(),m=grid[0].size();
        int tot=0,days=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int cnt=0;
        while(q.size()){
            cnt+=q.size();
            int k=q.size();
            while(k--){
                int a=q.front().first,b=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int ix=a+dx[i],iy=b+dy[i];
                    if(ix<0 or iy<0 or ix>=n or iy>=m or grid[ix][iy]!=1) continue;
                    grid[ix][iy]=2;
                    q.push({ix,iy});
                }
            }
            if(!q.empty()) days++;
        }
        if(cnt==tot) return days;
        return -1;
    }
};