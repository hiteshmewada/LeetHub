class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=target-(nums[i]+nums[j]);
                int l=j+1,h=n-1;
                while(l<h){
                    int b=(nums[l]+nums[h]);
                    if(b==a){
                        vector<int>vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[l]);vec.push_back(nums[h]);
                        st.insert(vec);
                        while(l<h and nums[l]==vec[2]) l++;
                        while(l<h and nums[h]==vec[3]) h--;
                    }
                    else if(b<a) l++;
                    else h--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x:st) ans.push_back({{x}});
        return  ans;
    }
};