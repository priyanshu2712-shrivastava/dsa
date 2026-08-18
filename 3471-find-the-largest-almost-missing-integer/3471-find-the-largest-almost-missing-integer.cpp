class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            for (int ind = i; ind < i + k; ind++) {
                st.insert(nums[ind]);
            }

            for (int x : st) {
                mp[x]++;
            }
        }

        int maxi = -1;

        for (auto it : mp) {
            if (it.second == 1) {
                maxi = max(maxi, it.first);
            }
        }

        return maxi;
    }
};