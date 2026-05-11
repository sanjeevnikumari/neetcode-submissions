class Codec {
public:

    // Serialize
    void dfsSerialize(TreeNode* root, string &s) {

        if(root == NULL) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        dfsSerialize(root->left, s);
        dfsSerialize(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";
        dfsSerialize(root, s);
        return s;
    }

    // Deserialize
    TreeNode* build(queue<string> &q) {

        if(q.empty()) return NULL;

        string val = q.front();
        q.pop();

        if(val == "#") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(q);
        root->right = build(q);

        return root;
    }

    TreeNode* deserialize(string data) {

        queue<string> q;
        string temp = "";

        for(char c : data) {

            if(c == ' ') {
                q.push(temp);
                temp = "";
            }
            else {
                temp += c;
            }
        }

        return build(q);
    }
};