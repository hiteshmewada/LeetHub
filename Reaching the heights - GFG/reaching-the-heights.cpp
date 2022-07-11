// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a,a+n);
    int l=0,r=n-1,check=1;
    vector<int>ans;
    while(l<=r){
        if(l==r) {
            ans.push_back(a[r]);
            return ans;
        }
        check+=(a[r]-a[l]);
        if(check<=1) return {-1};
        ans.push_back(a[r]);
        ans.push_back(a[l]);
        l++;r--;
    }
    return ans;
}
