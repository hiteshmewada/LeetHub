// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void computeLPS(vector<int>&v,int n,string s){
	    int len=0,i=1;
	    v[0]=0;
	    while(i<n){
	        if(s[i]==s[len]){
	            len++;
	            v[i]=len;
	            i++;
	        }
	        else{
	            if(len!=0){
	                len=v[len-1];
	            }
	            else{
	                v[i]=0;
	                i++;
	            }
	        }
	    }
	}
	int isRepeat(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    vector<int> lps(n);
	    computeLPS(lps,n,s);
	    int len=lps[n-1];
	    return (len>0 and n%(n-len)==0)?1:0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends