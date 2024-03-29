// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
/*  4
    10 6 3 3
    2
    ans=2
    
*/
class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<long long ,long long>mp;
        long long ans=0;
        for(long long i=0;i<n;i++){
            long long a=A[i];
            if(a>=K) a=a%K;
            long long b=K-a;
            if(b==K) b=0;
            // cout<<mp[b]<<" "<<b<<endl;
            if(mp[b]) ans+=mp[b];
            // cout<<mp[a]<<" "<<a<<endl;
            mp[a]++;
        }
        // ans+=(mp[0]-1);
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends