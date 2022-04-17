// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
long long getNumber(long long int num){
    string s=to_string(num);
    int n=s.size();
    int i=n/2-1,j=n/2;
    if(n%2) i++;
    while(j<n){
        s[j]=s[i];
        i--;j++;
    }
    return stoll(s);
}
	long long int closestPalindrome(long long int num){
	    // Code here
	    long long ans=getNumber(num);
	    long long gap=abs(ans-num);
	    for(int i=0;i<15;i++){
	        long long z=pow(10,i);
	        if(num>z){
	            long long temp=getNumber(num-z);
	            if(gap>=abs(temp-num)){
	                if(gap==abs(temp-num)) ans=min(ans,temp);
	                else{
	                    ans=temp;
	                    gap=abs(temp-num);
	                }
	            }
	        }
	        long long mx=1e15;
	        if(num+z<mx){
	            long long temp=getNumber(num+z);
	            if(gap>=abs(temp-num)){
	                if(gap==abs(temp-num)) ans=min(ans,temp);
	                else{
	                    ans=temp;
	                    gap=abs(temp-num);
	                }
	            }
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends