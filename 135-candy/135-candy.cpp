class Solution {
public:
    int count(int n){
        return (n*(n+1))/2;
    }
    int candy(vector<int>& r) {
        int ans=0,n=r.size();
        if(r.size()<=1) return r.size();
        int up=0,down=0,oldSlope=0;
        for(int i=1;i<n;i++){
            int newSlope=(r[i]>r[i-1])?1:(r[i]<r[i-1]?-1:0);
            if((oldSlope>0 and newSlope==0) or (oldSlope<0 and newSlope>=0)){
                ans+=count(up)+count(down)+max(up,down);
                up=0;down=0;
            }
            if(newSlope>0) up++;
            else if(newSlope<0) down++;
            else ans++;
            oldSlope=newSlope;
        }
        ans+=count(up)+count(down)+max(up,down)+1;
        return ans;
    }
};