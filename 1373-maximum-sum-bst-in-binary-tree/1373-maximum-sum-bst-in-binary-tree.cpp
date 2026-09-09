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
class info {
public:
    bool isBst;
    int mini;
    int maxi;
    int sum;
};

class Solution {
private:
    info solve(TreeNode* root, int &ans) {
        
        // Empty tree is a BST
        if (root == NULL) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        info l = solve(root->left, ans);
        info r = solve(root->right, ans);

        info temp;

        // Check if current subtree is BST
        if (l.isBst && r.isBst &&
            l.maxi < root->val &&
            root->val < r.mini) {

            temp.isBst = true;

            // Calculate sum
            temp.sum = l.sum + r.sum + root->val;

            // Update minimum and maximum
            temp.mini = min(root->val, l.mini);
            temp.maxi = max(root->val, r.maxi);

            // Update answer
            ans = max(ans, temp.sum);
        }
        else {
            temp.isBst = false;
            temp.mini = INT_MIN;
            temp.maxi = INT_MAX;
            temp.sum = 0;
        }

        return temp;
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};