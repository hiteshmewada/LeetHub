class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>pq;
        int m=image.size(),n=image[0].size();
        pq.push({sr,sc});
        char col=image[sr][sc];
        if(col==color) return image;
        while(pq.size()){
            auto p=pq.front();
            pq.pop();
            int i=p.first,j=p.second;
            image[i][j]=color;
            if(i+1<m and image[i+1][j]==col){
                pq.push({i+1,j});
            }
            if(i-1>=0 and image[i-1][j]==col){
                pq.push({i-1,j});
            }
            if(j+1<n and image[i][j+1]==col){
                pq.push({i,j+1});
            }
            if(j-1>=0 and image[i][j-1]==col){
                pq.push({i,j-1});
            }
        }
        return image;
    }
};