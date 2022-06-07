class Solution {
public:
    vector<int> majorityElement(vector<int>& n) {
        int n1=0,n2=0,c1=0,c2=0;
        for(auto x:n){
            if(x==n1) c1++;
            else if(x==n2) c2++;
            else if(c1==0){
                n1=x;
                c1=1;
            }
            else if(c2==0){
                n2=x;
                c2=1;
            }
            else{
                c1--;c2--;
            }
        }
        int cnt1=0,cnt2=0;
        for(auto x:n){
            if(x==n1) cnt1++;
            else if(x==n2) cnt2++;
        }
        vector<int>ans;
        if(cnt1>(n.size()/3)) ans.push_back(n1);
        if(cnt2>(n.size()/3)) ans.push_back(n2);
        return ans;
    }
};