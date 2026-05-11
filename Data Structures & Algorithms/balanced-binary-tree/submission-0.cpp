class Solution {
public:

    int height(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // if subtree already unbalanced
        if(leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // current node unbalanced
        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // return height
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        
        return height(root) != -1;
    }
};