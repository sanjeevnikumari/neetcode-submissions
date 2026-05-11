class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node mil gaya

            // Case 1: no child
            if (!root->left && !root->right) {
                return NULL;
            }

            // Case 2: one child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: two children
            TreeNode* temp = findMin(root->right); // successor
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};