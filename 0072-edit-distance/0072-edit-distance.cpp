class Solution {
public:
    
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        
        vector<int>pre(m+1),cur(m+1);
        
        for(int i=0;i<=m;i++) pre[i]=i;
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1])
                    cur[j]=pre[j-1];
                else{
                    int c1=1+pre[j]; // delete
                    int c2=1+ cur[j-1];  // insert
                    int c3=1+ pre[j-1]; // replace

                     cur[j]=min({c1,c2,c3});
                }
                    
            }
            pre=cur;
        }
        return pre[m];
        
    }
};