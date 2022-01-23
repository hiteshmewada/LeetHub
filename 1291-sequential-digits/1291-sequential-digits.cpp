class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v,ans;
        queue<int>q;
        for(int i=1;i<=9;i++) q.push(i);
        while(!q.empty()){
            int num=q.front();
            q.pop();
            if(num>=low and num<=high) ans.push_back(num);
            if(num>high) break;
            int a=num%10;
            if(a<9) q.push(num*10+a+1);
        }
        return ans;
    }
};