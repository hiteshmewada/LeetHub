class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>dif;
        for(int i=1;i<nums.size();i++){
            dif.push_back(nums[i-1]-nums[i]);
        }
        int cnt=0,neg=1,pos,ans=0;
        for(auto x:dif){
            // cout<<x<<" ";
            if(x<0 and neg){
                cnt++;neg=0;
            }
            else if(x>0){
                if(neg==0){
                    cnt++;
                    neg=1;
                }
            }
        }
        cnt++;
        ans=max(ans,cnt);
        pos=1,cnt=0;
        for(auto x:dif){
            if(x>0 and pos){
                cnt++;pos=0;
            }
            else if(x<0){
                if(pos==0){
                    cnt++;
                    pos=1;
                }
            }
        }
        cnt++;
        ans=max(ans,cnt);
        return ans;
    }
};