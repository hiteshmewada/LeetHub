// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        // code here
        int b,k=0;
        string p;
        for(int i=0;i<s.size();i++)
            {
                b=0;
                while(i+1<s.size() and s[i]==s[i+1]) {i++;b++;}
                if(!b)
                p+=s[i];
                else k++;
            }
            if(k)
            return remove(p);
            return p;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends