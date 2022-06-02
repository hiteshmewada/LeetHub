class Solution {
public:
    void sortColors(vector<int>& v) {
        int lo=0,mid=0,high=v.size()-1;
        while(mid<=high){
            switch(v[mid]){
                case 0:
                    swap(v[lo++],v[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(v[mid],v[high--]);
                    break;
            }
        }
    }
};