class Solution {
public:
    bool sumGame(string num) {
        int left = 0;
        int l = 0;
        int right = 0;
        int r = 0;
        int n = num.length();

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                l++;
            else
                left += num[i] - '0';
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                r++;
            else
                right += num[i] - '0';
        }

        return 2 * (left - right) != 9 * (r - l);
    }
};