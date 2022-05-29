// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool inBoard(int x,int y,int n){
      if(x>=n or y>=n or x<0 or y<0) return false;
      return true;
  }
    vector<vector<int>> formCoils(int n) {
        
        // code here
        /*
        n=1;
        The matrix is 
        1  2  3  4
        5  6  7  8
        9  10 11 12
        13 14 15 16
        So, the two coils are as given in the Ouput.
        10 6 2 3 4 8 12 16
        7 11 15 14 13 9 5 1 
        */
        n=4*n;
        vector<vector<int>>v(n,vector<int>(n,-1));
        int cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) v[i][j]=cnt++;
        }
        int xi=n/2-1,yi=n/2;
        vector<int>ans1,ans2;
        vector<string>direct={"down","left","up","right"};
        int dir=0;
        // cout<<xi<<" "<<yi<<" "<<v[xi][yi]<<endl;
        ans1.push_back(v[xi][yi]);
        int steps=2,incsteps=0;
        while(v[xi][yi]!=1){
            for(int i=0;i<steps;i++){
                if(v[xi][yi]==1) break;
                if(direct[dir]=="down") xi++;
                else if(direct[dir]=="left") yi--;
                else if(direct[dir]=="up") xi--;
                else yi++;
                if(inBoard(xi,yi,v.size())) ans1.push_back(v[xi][yi]);
            }
            dir=(dir+1)%4;
            incsteps++;
            if(incsteps%2==0) steps+=2;
        }
        for(auto x:ans1){
            ans2.push_back(n*n+1-x);
        }
        v.clear();
        v.push_back(ans2);
        v.push_back(ans1);
        return v;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends