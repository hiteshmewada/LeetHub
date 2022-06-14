// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int gcd(int a,int b){
	   // if(b==0) return a;
	   // return (b,b%a);
	   // return (b==0)?a:gcd(b,b%a);
	   return (b==0)?a:gcd(b,a%b);
	}
	int isRepeat(string s)
	{
	    // Your code goes here
	    unordered_map<char,int>mp;
	    int sum=0;
	    for(int i=0;i<s.size();i++) mp[s[i]]++;
	    int hcf=mp[s[0]];
	    for(auto x:mp) {
	        hcf=gcd(hcf,x.second);
	        sum+=x.second;
	    }
	    if(hcf==1)
         return 0;
         hcf=sum/hcf;
         string  temp;
            int i;
            for(i=0;i<hcf;i++) temp+=s[i];
            int k=0;
            for(i;i<s.size();i++){
                if(s[i]!=s[k]) return 0;
                k++;
                k%=hcf;
            }
            return 1;
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