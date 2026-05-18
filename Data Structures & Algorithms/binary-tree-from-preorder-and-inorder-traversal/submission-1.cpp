class Solution {
public:

    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder,
                    vector<int>& inorder,
                    int start,
                    int end) {

        if(start > end) {
            return NULL;
        }

        // root from preorder
        int rootVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootVal);

        // find root in inorder
        int index = start;

        while(inorder[index] != rootVal) {
            index++;
        }

        // build left subtree
        root->left =
            solve(preorder, inorder, start, index - 1);

        // build right subtree
        root->right =
            solve(preorder, inorder, index + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        return solve(preorder,
                     inorder,
                     0,
                     inorder.size() - 1);
    }
};