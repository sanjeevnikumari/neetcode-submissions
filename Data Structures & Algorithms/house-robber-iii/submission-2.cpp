class Solution {
public:

    unordered_map<TreeNode*, int> dp;

    int solve(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        // already calculated
        if(dp.find(root) != dp.end()) {
            return dp[root];
        }

        // rob current node
        int rob = root->val;

        if(root->left) {
            rob += solve(root->left->left);
            rob += solve(root->left->right);
        }

        if(root->right) {
            rob += solve(root->right->left);
            rob += solve(root->right->right);
        }

        // skip current node
        int skip = solve(root->left) + solve(root->right);

        // store answer
        dp[root] = max(rob, skip);

        return dp[root];
    }

    int rob(TreeNode* root) {
        return solve(root);
    }
};