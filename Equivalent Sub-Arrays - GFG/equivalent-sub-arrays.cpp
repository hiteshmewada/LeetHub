// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        int k=mp.size();
        int i=0,j=0,cnt=0;
        unordered_map<int,int>mp1;
        while(j<n){
            mp1[arr[j]]++;
            if(mp1.size()<k) j++;
            else if(mp1.size()==k){
                cnt+=n-j;
                while(mp1.size()==k){
                    mp1[arr[i]]--;
                    if(mp1[arr[i]]==0) mp1.erase(arr[i]);
                    i++;
                    if(mp1.size()==k) cnt+=n-j;
                }
                j++;
            }
        }
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends