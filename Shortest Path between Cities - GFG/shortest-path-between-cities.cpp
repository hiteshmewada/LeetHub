// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
        if(x==y) return 0;
        int maxi=max(x,y),mini=min(x,y);
        return 1+shortestPath(maxi/2,mini);
        // int fir=1,sec=1,ans1=0;
        // while(x>fir){
        //     fir+=sec;
        //     sec*=2;
        //     ans1++;
        // }
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends