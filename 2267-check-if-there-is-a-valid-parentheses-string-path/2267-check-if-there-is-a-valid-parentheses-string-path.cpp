class Solution {
private:
    vector<vector<vector<int>>> dp;
    int n, m;

    bool solve(int i, int j, int count, vector<vector<char>>& grid) {

        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            count++;
        else
            count--;

        if (count < 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return count == 0;

        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        bool down = solve(i + 1, j, count, grid);
        bool right = solve(i, j + 1, count, grid);

        return dp[i][j][count] = down || right;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2 != 0)
            return false;

        dp.assign(
            n,
            vector<vector<int>>(m,vector<int>(n + m + 1, -1)));

        return solve(0, 0, 0, grid);
    }
};