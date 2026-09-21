class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex + 1);

        triangle[0].push_back(1);

        if (rowIndex == 0)
            return triangle[rowIndex];

        triangle[1].push_back(1);
        triangle[1].push_back(1);

        if (rowIndex == 1)
            return triangle[rowIndex];

        for (int i = 2; i <= rowIndex; i++) {
            triangle[i].push_back(1);

            for (int j = 1; j < i; j++) {
                triangle[i].push_back(
                    triangle[i - 1][j - 1] + triangle[i - 1][j]
                );
            }

            triangle[i].push_back(1);
        }

        return triangle[rowIndex];
    }
};