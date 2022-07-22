class Solution {
public:
    int val(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()){
                if(s[i]=='I'){
                    if(s[i+1]=='V') {ans+=4;i++;}
                    else if(s[i+1]=='X') {ans+=9;i++;}
                    else ans+=val(s[i]);
                }
                else if(s[i]=='X'){
                    if(s[i+1]=='L') {ans+=40;i++;}
                    else if(s[i+1]=='C') {ans+=90;i++;}
                    else ans+=val(s[i]);
                }
                else if(s[i]=='C'){
                    if(s[i+1]=='D') {ans+=400;i++;}
                    else if(s[i+1]=='M') {ans+=900;i++;}
                    else ans+=val(s[i]);
                }
                else{
                    ans+=val(s[i]);
                }
            }
            else ans+=val(s[i]);
        }
        return ans;
    }
};