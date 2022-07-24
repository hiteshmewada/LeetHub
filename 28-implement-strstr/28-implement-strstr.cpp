class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        
        for(int i=0;i<haystack.size();i++){
            int j=0,c=i;
            while(i<haystack.size() and j<needle.size() and haystack[i]==needle[j]){
                j++;i++;
            }
            if(j==needle.size()) return c;
            else i=c;
        }
        return -1;
    }
};