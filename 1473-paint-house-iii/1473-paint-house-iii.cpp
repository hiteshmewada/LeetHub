class Solution {
public:
    // index,count,color
    
    const int max_cost=1000001;
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<int>>prevMemo(target+1,vector<int>(n,max_cost));
        for(int color=1;color<=n;color++){
            if(houses[0]==color) prevMemo[1][color-1]=0;
            else if(!houses[0])
                prevMemo[1][color-1]=cost[0][color-1];
        }
        for(int house=1;house<m;house++){
            // new memo
            vector<vector<int>>memo(target+1,vector<int>(n,max_cost));
            for(int neighborhoods=1;neighborhoods<=min(target,house+1);neighborhoods++){
                for(int color=1;color<=n;color++){
                    if(houses[house] and color!=houses[house]) continue;
                   int curCost=max_cost;
                    for(int prevColor=1;prevColor<=n;prevColor++){
                        if(prevColor!=color){
                            curCost=min(curCost,prevMemo[neighborhoods-1][prevColor-1]);
                        }
                        else{
                            curCost=min(curCost,prevMemo[neighborhoods][prevColor-1]);
                        }
                    }
                    // cost of painting house
                    int costToPaint=houses[house]?0:cost[house][color-1];
                    memo[neighborhoods][color-1]=curCost+costToPaint;
                 }
            }
            prevMemo=memo;
        }
        int minCost=max_cost;
        for(int color=1;color<=n;color++){
            minCost=min(minCost,prevMemo[target][color-1]);
        }
        return minCost==max_cost?-1:minCost;
    }
};