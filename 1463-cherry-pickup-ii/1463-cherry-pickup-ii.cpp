class Solution {
private:
    int solve(int i, int j1, int j2, int row, int col,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp) {
        // Out of bounds
        if (j1 < 0 || j1 >= col || j2 < 0 || j2 >= col)
            return INT_MIN;
        // Last row
        if (i == row - 1) {
            if (j1 == j2)
                return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        // Current cherries
        int curr;
        if (j1 == j2)
            curr = grid[i][j1];
        else
            curr = grid[i][j1] + grid[i][j2];
        int ans = INT_MIN;
        int delta[3] = {-1, 0, 1};
        // 3 choices for robot 1
        for (int a = 0; a < 3; a++) {
            // 3 choices for robot 2
            for (int b = 0; b < 3; b++) {

                int newj1 = j1 + delta[a];
                int newj2 = j2 + delta[b];
                int now=solve(i+1,newj1,newj2,row,col,grid,dp);
                if(now!=INT_MIN){
                    ans = max(ans, curr + now);
                }
            }
        }

        return dp[i][j1][j2]=ans;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        return solve(0, 0, col - 1, row, col, grid,dp);
    }
};