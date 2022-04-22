// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
        if(a<b) swap(a,b);
        int ans,cy=0,j=0;
        while(a){
            if(a%2 and b%2){
                if(cy) ans+=(1<<j);
                cy=1;
            }
            else if(a%2 or b%2){
                if(cy){
                    cy=1;
                }
                else ans+=(1<<j);
            }
            else{
                if(cy){
                    ans+=(1<<j);
                    cy=0;
                }
            }
            j++;
            a/=2;b/=2;
        }
        if(cy) ans+=(1<<j);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends