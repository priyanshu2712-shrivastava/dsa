class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int preSum = 0, cnt = 0;

        mpp[0] = 1;

        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            int remove = preSum - k;

            if (mpp.find(remove) != mpp.end()) {
                cnt += mpp[remove];
            }

            mpp[preSum]++;
        }
        return cnt;
    }
};
