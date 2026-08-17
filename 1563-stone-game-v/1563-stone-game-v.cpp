class Solution {
private:
    int solve(vector<int>& stoneValue, int s, int e, vector<int>& prefix,vector<vector<int>> &dp) {

        if (s == e)
            return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int ans = 0;

        // Try every possible split
        for (int k = s; k < e; k++) {

            int left = prefix[k + 1] - prefix[s];
            int right = prefix[e + 1] - prefix[k + 1];

            if (left < right) {
                ans = max(ans,
                          left + solve(stoneValue, s, k, prefix,dp));
            }
            else if (right < left) {
                ans = max(ans,
                          right + solve(stoneValue, k + 1, e, prefix,dp));
            }
            else {
                ans = max(ans,
                          left + max(
                              solve(stoneValue, s, k, prefix,dp),
                              solve(stoneValue, k + 1, e, prefix,dp)
                          ));
            }
        }

        return dp[s][e]=ans;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(stoneValue, 0, n - 1, prefix,dp);
    }
};