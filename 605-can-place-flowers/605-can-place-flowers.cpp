class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans=0,b;
        if(flowerbed.size()==1){
            if(flowerbed[0]==0 and n==1) return true;
            else if(n==0) return true;
            else return false;
        }
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                if(i-1>=0 and i+1<flowerbed.size() and flowerbed[i-1]==0 and flowerbed[i+1]==0)
                    {ans++;flowerbed[i]=1;}
                else if(i+1>=flowerbed.size() and (i-1)>=0 and flowerbed[i-1]==0)
                   {ans++;flowerbed[i]=1;}
                else if(i+1<flowerbed.size() and (i-1)<0 and flowerbed[i+1]==0)
                   {ans++;flowerbed[i]=1;}
            }
        }
        
        if(ans>=n) return true;
        else return false;
    }
};