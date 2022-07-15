class Solution {
public:
    vector<vector<int>>grid;
    
    int maxAreaOfIsland(vector<vector<int>>& gri) {
        grid=gri;
        int n=grid.size(),a=grid[0].size();
        bool vis[n][a];
        memset(vis,false,sizeof(vis));
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<a;c++){
                if(grid[r][c]==1 and !vis[r][c]){
                    int shape=0;
                    stack<pair<int,int>>st;
                    st.push({r,c});
                    vis[r][c]=true;
                    while(!st.empty()){
                        pair<int,int> node=st.top();
                        st.pop();
                        int r1=node.first,c1=node.second;
                        shape++;
                        for(int k=0;k<4;k++){
                            int nr=r1+dx[k],nc=c1+dy[k];
                            if(nr>=0 and nr<n and nc<a and nc>=0 and                                    grid[nr][nc]==1 and !vis[nr][nc]){
                                st.push({nr,nc});
                                vis[nr][nc]=true;
                            }
                        }
                    }
                    ans=max(ans,shape);
                }
            }
        }
        return ans;
    }
};