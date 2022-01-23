// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        // vector<int>v;
        string s;
        int a=0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' and str[i]<='9'){
                a+=str[i]-'0';
            }
            else s+=str[i];
        }
        sort(s.begin(),s.end());
        s+=to_string(a);
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends