// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
// class Trie{
//     public:
//         bool isLast;
//         Trie* child[26];
//         Trie(){
//             isLast=false;
//             memset(child,NULL,sizeof(child));
//         }
// };
// void addWord(string word,Node* root){
//     for(auto x:word){
//         ++root->
//     }
// }
class Solution
{
    public:
    // Trie* root;
    vector<string> findPrefixes(string arr[], int n)
    {
        vector<string>v;
        for(int i=0;i<n;i++){
            int len=0,trav=0;
            while(trav<n){
                if(trav==i) trav++;
                else if(arr[i].substr(0,len)==arr[trav].substr(0,len))
                    len++;
                else trav++;
            }
            v.push_back(arr[i].substr(0,len));
        }
        return v;
        //code here
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<arr[i].size();j++){
        //         int ind=arr[i][j]-'a';
        //         if(root->child[ind]==NULL)
        //             root->child[ind]=new Trie();
        //         root=root->child[ind];
        //     }
        //     root->isLast=true;
        // }
        // unordered_set<string>st;
        // Trie* cur;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<arr[i].size();j++){
        //         int ind=arr[i][j]-'a';
        //         if(root->child[ind]==NULL)
        //             root->child[ind]=new Trie();
        //         root=root->child[ind];
        //     }
        //     root->isLast=true;
        // }
        
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends