class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) {
            return NULL;
        }

        // swap left and right
        swap(root->left, root->right);

        // recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};