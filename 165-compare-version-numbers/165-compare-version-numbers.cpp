class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        int i=0,j=0;
        while(i<n or j<m){
            int a=0,b=0;
            while(i<n and version1[i]!='.'){
                a=a*10+(version1[i]-'0');i++;
            }
            while(j<m and version2[j]!='.'){
                b=b*10+(version2[j]-'0');j++;
            }
            if(a<b) return -1;
            else if(a>b) return 1;
            i++;j++;
        }
        return 0;
    }
};