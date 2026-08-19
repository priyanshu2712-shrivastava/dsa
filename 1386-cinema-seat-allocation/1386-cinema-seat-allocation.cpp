class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for (auto &x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        int ans = 2 * n;

        for (auto &[row, seats] : mp) {
            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat : seats) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right) {
                continue;
            }
            else if (left || middle || right) {
                ans--;
            }
            else {
                ans -= 2;
            }
        }

        return ans;
    }
};