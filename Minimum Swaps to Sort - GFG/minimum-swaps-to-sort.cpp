// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int>mp;
	    for(int i=0;i<nums.size();i++)
	        mp[nums[i]]=i;
	    sort(nums.begin(),nums.end());
	    int swaps=0;
	    for(int i=0;i<nums.size();){
	       // pair<int,int>p=v[i];
	       // int value=p.first,index=p.second;
	        if(mp[nums[i]]!=i){
	            swaps++;
	            swap(nums[mp[nums[i]]],nums[i]);
	           // i--;
	        }
	        else i++;
	    }
	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends