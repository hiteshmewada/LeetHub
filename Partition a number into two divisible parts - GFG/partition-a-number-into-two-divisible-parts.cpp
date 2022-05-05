// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        // code here 
        int n=s.size(),i;
        string p="";
        for( i=0;i<n;i++){
            p+=s[i];
            if(p.size()==n) return "-1";
            int n1=stoi(p),n2=stoi(s.substr(i+1,n-i));
            // cout<<n1<<" "<<n2;
            if(n1%a==0 and n2%b==0) break;
        }
        
        return p+" "+s.substr(i+1,n-i);
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends