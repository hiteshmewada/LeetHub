class Solution {
public:
    string reverseWords(string s) {
        int ind=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                if(ind!=0) s[ind++]=' ';
                int j=i;
                while(j<s.size() and s[j]!=' '){
                    s[ind++]=s[j++];
                }
                reverse(s.begin()+ind-(j-i),s.begin()+ind);
                i=j;
            }
        }
        s.erase(s.begin()+ind,s.end());
        return s;
    }
};