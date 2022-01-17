class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        int i=0;
        while(i<s.size()){
            string p;
            while(i<s.size() and s[i]!=' '){
                p+=s[i];
                i++;
            }
            v.push_back(p);
            i++;
        }
        if(v.size()==pattern.size()){
            for(int i=0;i<pattern.size();i++){
                for(int j=i+1;j<pattern.size();j++){
                    if(pattern[i]==pattern[j] and v[i]!=v[j])
                        return false;
                    if(pattern[i]!=pattern[j] and v[i]==v[j])
                        return false;
                }
            }
            return true;
        }
        return false;
    }
};