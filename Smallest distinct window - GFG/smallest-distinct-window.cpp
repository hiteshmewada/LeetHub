// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here  
        unordered_map<char,int>mp;
        for(auto x:s) mp[x]++;
        unordered_map<char,int>mp1;
        int i=0,j=0,ans=s.size();
        while(i<s.size()){
            mp1[s[i]]++;
            if(mp.size()==mp1.size()){
                ans=min(ans,i-j+1);
                while(mp.size()==mp1.size()){
                    mp1[s[j]]--;
                    if(mp1[s[j]]==0) mp1.erase(s[j]);
                    ans=min(ans,i-j+1);
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends