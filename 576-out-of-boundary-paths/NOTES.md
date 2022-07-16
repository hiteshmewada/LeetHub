Recursion
​
class Solution {
public:
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
if(startRow<0 or startRow>=m or startColumn<0 or startColumn>=n) return 1;
if(maxMove==0) return 0;
return (findPaths(m,n,maxMove-1,startRow+1,startColumn)+
findPaths(m,n,maxMove-1,startRow-1,startColumn)+
findPaths(m,n,maxMove-1,startRow,startColumn+1)+
findPaths(m,n,maxMove-1,startRow,startColumn-1));
}
};