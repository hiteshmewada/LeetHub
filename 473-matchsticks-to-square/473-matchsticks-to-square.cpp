class Solution {
public:
    vector<int>sides;
    bool dfs(vector<int>& m, int i, int tar){
        if(i==m.size()){
            return (sides[0]==sides[1] and 
            sides[1]==sides[2] and sides[2]==sides[3]);
        }
        for(int j=0;j<4;j++){
            if(sides[j]+m[i]>tar) continue;
            int k=j;
            while(--k>=0){
                if(sides[k]==sides[j]) break;
            }
            if(k!=-1) continue;
            sides[j]+=m[i];
            if(dfs(m,i+1,tar)) return true;
            sides[j]-=m[i];
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        if(m.size()<4) return false;
        sort(m.begin(),m.end(),greater<int>());
        int sum=0;
        for(auto x:m) sum+=x;
        if(sum%4!=0) return false;
        sides.resize(4,0);
        return dfs(m,0,sum/4);
    }
};