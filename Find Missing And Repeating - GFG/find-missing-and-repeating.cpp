// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans=new int[2];
        int i=0;
        while(i<n){
            if(arr[i]!=arr[arr[i]-1])
                swap(arr[i],arr[arr[i]-1]);
            else i++;
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                a=i+1;
                b=arr[i];
                break;
            }
        }
        ans[0]=b;
        ans[1]=a;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends