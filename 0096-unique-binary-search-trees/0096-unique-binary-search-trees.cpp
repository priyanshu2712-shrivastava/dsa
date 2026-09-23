class Solution {
public:

    int solve(int start, int end,vector<vector<int>>& dp) {

        // Empty subtree
        if (start > end)
            return 1;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans = 0;

        for (int i = start; i <= end; i++) {

            // Number of possible left subtrees
            int left = solve(start, i - 1,dp);

            // Number of possible right subtrees
            int right = solve(i + 1, end,dp);

            // Every left subtree can pair with every right subtree
            ans += left * right;
        }

        return dp[start][end]=ans;
    }

    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1, n,dp);
    }
};