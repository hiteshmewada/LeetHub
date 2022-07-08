class Solution {
public:
    // index,count,color
    int memo[100][100][21];
    const int max_cost=1000001;
    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int target,int curIndex, int neighborhoodCount, int prevHouseColor){
        if(curIndex==houses.size()){
            return neighborhoodCount==target?0:max_cost;
        }
        if(neighborhoodCount>target) return max_cost;
        if(memo[curIndex][neighborhoodCount][prevHouseColor]!=-1)
            return memo[curIndex][neighborhoodCount][prevHouseColor];
        int minCost=max_cost;
        if(houses[curIndex]){
            int newNeighborHoodCount=neighborhoodCount+(houses[curIndex]!=prevHouseColor); minCost=findMinCost(houses,cost,target,curIndex+1,newNeighborHoodCount,houses[curIndex]);
        }
        else{
            int totalColors=cost[0].size();
            for(int color=1;color<=totalColors;color++){
                int newNeighborHoodCount=neighborhoodCount+(color!=prevHouseColor); 
                int currCost=cost[curIndex][color-1] + findMinCost(houses,cost,target,curIndex+1,newNeighborHoodCount,color);
                minCost=min(minCost,currCost);
            }
        }
        return memo[curIndex][neighborhoodCount][prevHouseColor]=minCost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo,-1,sizeof(memo));
        int ans=findMinCost(houses,cost,target,0,0,0);
        return ans==max_cost?-1:ans;
    }
};