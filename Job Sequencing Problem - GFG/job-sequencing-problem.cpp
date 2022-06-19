// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // vector<pair<int,int>>v;
        // for(int i=0;i<n;i++){
        //     v.push_back({arr[i].dead,arr[i].profit});
        // }
        sort(arr,arr+n,[&](Job a,Job b){
           return a.profit>b.profit;
        });
        int last=-1,ans=0,cnt=0;
        int mx_dead=arr[0].dead;
        for(int i=1;i<n;i++) mx_dead=max(mx_dead,arr[i].dead);
        int job_slot[mx_dead+1];
        memset(job_slot,-1,sizeof(job_slot));
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(job_slot[j]==-1){
                    job_slot[j]=i;
                    cnt++;
                    ans+=arr[i].profit;
                    break;
                }
            }
            // if(v[i].first>last){
            //     last=v[i].first;
            //     ans+=v[i].second;
            //     cnt++;
            // }
        }
        return {cnt,ans};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends