Brute Force
class Solution {
public:
int largestRectangleArea(vector<int>& h) {
int n=h.size();
int ans=INT_MIN;
for(int i=0;i<n;i++){
int minHeight=INT_MAX;
for(int j=i;j<n;j++){
minHeight=min(minHeight,h[j]);
ans=max(ans,(j-i+1)*minHeight);
}
}
return ans;
}
};
​
class Solution {
public:
int largestRectangleArea(vector<int>& h) {
int n=h.size();
int ans=INT_MIN;
stack<int>st;
vector<int>leftSmall(n,0),rightSmall(n,0);
for(int i=0;i<n;i++){
while(!st.empty() and h[st.top()]>=h[i]) st.pop();
if(st.empty()) leftSmall[i]=0;
else leftSmall[i]=st.top()+1;
st.push(i);
}
while(st.size()) st.pop();
for(int i=n-1;i>=0;i--){
while(!st.empty() and h[st.top()]>=h[i]) st.pop();
if(st.empty()) rightSmall[i]=n-1;
else rightSmall[i]=st.top()-1;
st.push(i);
}
for(int i=0;i<n;i++){
ans=max(ans,h[i]*(rightSmall[i]-leftSmall[i]+1));
}
return ans;
}
};