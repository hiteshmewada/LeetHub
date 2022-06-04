class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n=in.size();
        int st=in[0][0],end=in[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            cout<<st<<" "<<end<<endl;
            if(in[i][0]>=st and in[i][1]<=end) continue;
            if(in[i][0]>=st and in[i][0]<=end) {
                end=in[i][1];continue;
            }
            else{
                ans.push_back({st,end});
                st=in[i][0];
                end=in[i][1];
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};