// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
        string ans;
        for(int i=0;i<s.size();i++){
            string p;
            while(i<s.size() and s[i]!='.') {
                p+=s[i];
                i++;
            }
            int j=0;
                while(j<p.size() and p[j]=='0') j++;
                if(j>=p.size()) ans+='0';
                else {
                    while(j<p.size()) ans+=p[j++];
                }
            if(i<s.size()) ans+='.';
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends