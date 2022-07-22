Brute force
​
class Solution {
public:
string reverseWords(string s) {
vector<string>v;
string ans;
for(int i=s.size()-1;i>=0;i--){
string p="";
while(i>=0 and s[i]!=' ') {
p+=s[i];
i--;
}
reverse(p.begin(),p.end());
// ans+=p;
if( p.size()>0) v.push_back(p);
// ans+=' ';
}
for(int i=0;i<v.size()-1;i++){ ans+=v[i];ans+=' ';}
ans+=v[v.size()-1];
int j=ans.size()-1;
return ans;
}
};