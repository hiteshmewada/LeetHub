class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        q.push(start);
        int ans=0;
        unordered_set<string>vis;
        vis.insert(start);
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string s=q.front();
                q.pop();
                if(s==end) return ans;
                for(char c:"ACGT"){
                    for(int j=0;j<s.size();j++){
                        string  temp=s;
                        temp[j]=c;
                        if(!vis.count(temp) and find(bank.begin(),bank.end(),temp)!=bank.end())
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};