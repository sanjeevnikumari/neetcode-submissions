class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // both null
        if(p == NULL && q == NULL) {
            return true;
        }

        // one null or values different
        if(p == NULL || q == NULL || p->val != q->val) {
            return false;
        }

        // check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};