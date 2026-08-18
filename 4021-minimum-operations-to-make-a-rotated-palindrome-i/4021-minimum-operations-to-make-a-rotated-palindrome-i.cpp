class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int min_ops = 1e9;

        for (int k = 0; k < n; ++k) {
            int current_ops = k; // Cost of k left rotations
            
            for (int i = 0; i < n / 2; ++i) {
                char c1 = s[(k + i) % n];
                char c2 = s[(k + n - 1 - i) % n];

                int diff1 = (c2 - c1 + 26) % 26;
                int diff2 = (c1 - c2 + 26) % 26;
                
                current_ops += min(diff1, diff2);
            }

            min_ops = min(min_ops, current_ops);
        }

        return min_ops;
    }
};