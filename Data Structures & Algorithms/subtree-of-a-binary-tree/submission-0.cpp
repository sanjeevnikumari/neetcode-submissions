class Solution {
public:

    bool isSame(TreeNode* p, TreeNode* q) {

        if(p == NULL && q == NULL) {
            return true;
        }

        if(p == NULL || q == NULL || p->val != q->val) {
            return false;
        }

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == NULL) {
            return true;
        }

        if(root == NULL) {
            return false;
        }

        // check current node
        if(isSame(root, subRoot)) {
            return true;
        }

        // search left or right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};