/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& temp) {
        if (root == NULL) return;

        sum -= root->val;

        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (root->left) {
            temp.push_back(root->left->val);
            solve(root->left, sum, ans, temp);
            temp.pop_back();
        }

        if (root->right) {
            temp.push_back(root->right->val);
            solve(root->right, sum, ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        if (root == NULL) return ans;

        temp.push_back(root->val);
        solve(root, targetSum, ans, temp);

        return ans;
    }
};