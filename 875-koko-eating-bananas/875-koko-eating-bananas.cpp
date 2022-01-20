class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long mn=h,l=1,hi=*max_element(piles.begin(),piles.end());
        while(l<hi){
            // if(l<0 or h<0) break;
            long long mid=l+(hi-l)/2,b=0;
            // if(mid==0) break;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0)
                b+=piles[i]/mid;
                else b+=(piles[i]/mid)+1;
            }
            
            if(b<=h){
                mn=min(mn,mid);
                hi=mid;
            }
            else l=mid+1;
            cout<<l<<" "<<hi<<endl;
        }
        return hi;
    }
};