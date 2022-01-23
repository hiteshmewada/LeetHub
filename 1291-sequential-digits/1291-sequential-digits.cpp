class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v,ans;
        // v.push_back(123456789);
        int b=1;
        while(b<=9){
            for(int i=1;i<=9-(b-1);i++){
                int a=i;
                for(int j=i+1;j<=b+i-1;j++)
                {
                    a=a*10+j;
                }
                v.push_back(a);
                // cout<<a<<endl;
            }
            b++;
        }
        sort(v.begin(),v.end());
        int i=upper_bound(v.begin(),v.end(),low-1)-v.begin();
        int j=lower_bound(v.begin(),v.end(),high+1)-v.begin();
        for(int c=i;c<j;c++) ans.push_back(v[c]);
        // if(i-1>=0 and v[i-1]==low) ans.push_back(v[i-1]);
        // if(j+1<v.size() and v[j+1]==high) ans.push_back(v[j+1]);
        cout<<i<<" "<<j;
        sort(ans.begin(),ans.end());
        return ans;
    }
};