class Solution {
public:
    bool detectCapitalUse(string word) {
        int f=0,g=0;
        for(int i=0;i<word.size();i++){
            if(i==0 ){
                if(word[i]>='A' and word[i]<='Z'){
                    f=1;
                }
                else g++;
                continue;
            }
            if(f>1){
                if(word[i]>='A' and word[i]<='Z') f++;
                else return false;
                continue;
            }
            if(word[i]>='A' and word[i]<='Z'){
                if(f==0) return false;
                else if(g and g!=word.size()-1) return false;
                else f++;
            }
            else{
                g++;
            }
        }
        return true;
    }
};