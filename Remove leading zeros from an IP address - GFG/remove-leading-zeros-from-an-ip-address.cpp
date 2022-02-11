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
        bool ok=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.') ok=true;
            else{
                if(s[i]=='0'){
                    if(i==s.size()-1) break;
                    if(ok and s[i+1]!='.'){
                        s.erase(i,1);
                        i--;
                    }
                }
                else ok=false;
            }
        }
        return s;
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