// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
vector<int>findPrime(int n){
    set<int>st;
    vector<int>ans;
    int c=2;
    while(n>1){
        if(n%c==0){
            st.insert(c);
            n/=c;
        }
        else c++;
    }
    for(auto x:st) ans.push_back(x);
    return ans;
}
int rCnModP(int n,int r,int p){
    if(r==0 or r==n) return 1;
    int nCr[r+1];
    memset(nCr,0,sizeof(nCr));
    nCr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,r);j>0;j--){
            nCr[j]=(nCr[j]+nCr[j-1])%p;
        }
    }
    return nCr[r];
}
int findByCrt(vector<int>x, vector<int>r){
    auto N=x.size();
    int  min_x=0;
    while(true){
        bool found=true;
        for(int i=0;i<N;i++){
            if(min_x%x[i]!=r[i]){
                found=false;
                break;
            }
        }
        if(found) return min_x;
        min_x++;
    }
}
int rcnModPrimeLucas(int n,int r,int p){
    if(r==0) return 1;
    return (rcnModPrimeLucas(n/p,r/p,p)*rCnModP(n%p,r%p,p))%p;
}
int nCrModM(int n, int r, int m) {
    // Code here
    vector<int>primes,rem;
    primes=findPrime(m);
    for(auto x:primes){
        rem.push_back(rcnModPrimeLucas(n,r,x));
    }
    return findByCrt(primes,rem);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, r, m;
		cin >> n >> r >> m;
		Solution obj;
		int ans = obj.nCrModM(n, r, m);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends