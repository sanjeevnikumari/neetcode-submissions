class Solution {
public:

    pair<int,int> dfs(TreeNode* root) {

        if(root == NULL) {
            return {0,0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // rob current node
        int rob =
            root->val +
            left.second +
            right.second;

        // skip current node
        int skip =
            max(left.first, left.second) +
            max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {

        auto ans = dfs(root);

        return max(ans.first, ans.second);
    }
};