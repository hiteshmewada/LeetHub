// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool rec(int N, int K, int M, vector<int> &A, int  ind){
        if(ind>=N) return true;
        for(int i=ind+K-1;i<N;i++){
            if(A[i]-A[ind]>M) return false;
            if(rec(N,K,M,A,i+1)) return true;
        }
        return false;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        /*
        10 5 25
        75 87 31 100 44 14 55 77 35 12
        12 14 31 35 44 55 75 77 87 100
        10 4 18
        73 31 30 59 61 85 21 95 27 72
        21 27 30 31 . 59 61 72 73 . 85 95
        5 2 3
        8 3 9 1 2
        1 2 3 . 8 9
        10 2 19
        96 39 24 89 54 71 38 41 75 54
        24 38 39 41 . 54 54 71 . 75 89 96
        */
        vector<int>ind;
        sort(A.begin(),A.end());
        return rec(N,K,M,A,0);
        // int a=A[0];
        // ind.push_back(0);
        // for(int i=1;i<N;i++){
        //     if(A[i]-a>M){
        //         ind.push_back(i);
        //         a=A[i];
        //     }
        // }
        // // ind.push_back(N-1);
        // for(int i=1;i<ind.size();i++){
            
        //     if(ind[i]-ind[i-1]<K) return false;
        // }
        // if((N-ind[ind.size()-1])<K) return false;
        // return true;
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends