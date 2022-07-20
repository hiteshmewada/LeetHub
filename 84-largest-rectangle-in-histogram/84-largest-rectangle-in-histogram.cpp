class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int ans=INT_MIN;
        stack<int>st;
        vector<int>leftSmall(n,0),rightSmall(n,0);
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or h[st.top()]>=h[i])){
                int height=h[st.top()];
                st.pop();
                int width;
                if(st.size()==0) width=i;
                else width=i-st.top()-1;
                ans=max(ans,height*width);
            }
            st.push(i);
        }
        
        return ans;
    }
};