// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        // code here
        vector<pair<int,int>>v;
        for(int i=0;i<N;i++) v.push_back({start[i],end[i]});
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>>pq; // ,min heap
        int cnt=0,i=0,d=0;
        while(!pq.empty() or i<N){
            if(pq.size()==0)
                d=v[i].first;
            while(i<N and v[i].first<=d)
                pq.push(v[i++].second);
            pq.pop();
            cnt++;
            d++;
            while(!pq.empty() and pq.top()<d) pq.pop();
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends