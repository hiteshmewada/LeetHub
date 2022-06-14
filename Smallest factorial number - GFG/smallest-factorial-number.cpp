// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int zeroes(int n){
        int ans=0;
        for(int i=5;i<=n;i*=5) ans+=n/i;
        return ans;
    }
        int findNum(int n)
        {
        //complete the function here
        // 5,2,10*2=20
            int low=0,high=5*n;
            while(low<high){
                int mid=low+(high-low)/2;
                int a=zeroes(mid);
                if(a>=n) high=mid;
                else low=mid+1;
            }
            return low;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends