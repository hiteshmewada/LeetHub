//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        int n1=0,n2=0,sum=0;
        for(int i=0;i<N;i++) sum^=Arr[i];
        int bit=0;
        for(int i=31;i>=0;i--){
            if(sum&(1<<i)) bit=(1<<i);
        }
        sum=bit;
        for(int i=0;i<N;i++){
            if(Arr[i]&sum) n1^=Arr[i];
            else n2^=Arr[i];
        }
        if(n1<n2) swap(n1,n2);
        return {n1,n2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends