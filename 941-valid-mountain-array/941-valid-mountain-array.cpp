class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int a=*max_element(arr.begin(),arr.end()),b=0;
        if(a==arr[0]) return false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==a) {b=i;break;}
            if(i+1<arr.size() and arr[i]<arr[i+1]) continue;
            else return false;
        }
        if(b+1==arr.size()) return false;
        for(int i=b;i<arr.size();i++){
            // if(arr[i]==a) break;
            if(i+1<arr.size() and arr[i]>arr[i+1]) continue;
            else if(i+1==arr.size()) continue;
            else return false;
        }
        return true;
    }
};