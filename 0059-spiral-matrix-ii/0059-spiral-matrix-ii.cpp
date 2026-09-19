class Solution {
    int num=1;
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int startRow=0;
        int endRow=n-1;
        int startCol=0;
        int endCol=n-1;
        while(num<=n*n){
            for(int i=startCol;i<=endCol && num<=n*n;i++){
                ans[startRow][i]=num++;
            }
            startRow++;
            for(int i=startRow;i<=endRow && num<=n*n;i++){
                ans[i][endCol]=num++;
            }
            endCol--;
            for(int i=endCol;i>=startCol && num<=n*n;i--){
                ans[endRow][i]=num++;
            }
            endRow--;
            for(int i=endRow;i>=startRow && num<=n*n;i--){
                ans[i][startCol]=num++;
            }
            startCol++;
        }
        return ans;
    }
};