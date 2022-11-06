class Solution {
public:
    string orderlyQueue(string s, int k) {
         string ans=s;
        if(k==1){
           
            for(int i=0;i<s.size();i++){
                string t=s.substr(i)+s.substr(0,i);
                if(t<ans) ans=t;
            }
            
        }
        else {
            sort(s.begin(),s.end());
            return s;
        }
        return ans;
    }
};