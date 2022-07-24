class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int index=0;
        int ans=0;
        int sign=1;
        
        while(index<n and s[index]==' ') index++;
        
        if(index<n and s[index]=='+'){
            sign=1;index++;
        }
        else if(index<n and s[index]=='-'){
            sign=-1;index++;
        }
        
        while(index<n and isdigit(s[index])){
            int dig=s[index]-'0';
            if(ans>INT_MAX/10 or (ans==INT_MAX/10 and dig>INT_MAX%10))
            {
                if(sign==1) return INT_MAX;
                else return INT_MIN;
            }
            ans=10*ans+dig;
            index++;
        }
        return sign*ans;
    }
};