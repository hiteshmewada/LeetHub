Recursion
​
class Solution {
public:
vector<int>sides;
bool dfs(vector<int>& m, int i){
if(i==m.size()){
return (sides[0]==sides[1] and
sides[1]==sides[2] and sides[2]==sides[3]);
}
for(int j=0;j<4;j++){
sides[j]+=m[i];
if(dfs(m,i+1)) return true;
sides[j]-=m[i];
}
return false;
}
bool makesquare(vector<int>& m) {
if(m.size()==0) return false;
sides.resize(4,0);
return dfs(m,0);
}
};