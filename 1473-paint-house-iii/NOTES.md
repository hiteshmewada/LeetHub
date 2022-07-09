}
for(int house=1;house<m;house++){
for(int neighborhoods=1;neighborhoods<=min(target,house+1);neighborhoods++){
for(int color=1;color<=n;color++){
if(houses[house] and color!=houses[house]) continue;
int curCost=max_cost;
for(int prevColor=1;prevColor<=n;prevColor++){
if(prevColor!=color){
curCost=min(curCost,memo[house-1][neighborhoods-1][prevColor-1]);
}
else{
curCost=min(curCost,memo[house-1][neighborhoods][prevColor-1]);
}
}
// cost of painting house
int costToPaint=houses[house]?0:cost[house][color-1];
memo[house][neighborhoods][color-1]=curCost+costToPaint;
}
}
}
int minCost=max_cost;
for(int color=1;color<=n;color++){
minCost=min(minCost,memo[m-1][target][color-1]);
}
return minCost==max_cost?-1:minCost;
}
};