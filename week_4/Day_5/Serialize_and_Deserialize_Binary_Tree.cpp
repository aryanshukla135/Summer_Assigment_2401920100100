/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root);

        string temp = "";
        if(root == nullptr){
            return temp;
        }
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == nullptr){
                temp.push_back('#,');
                continue;
            }
            temp+=to_string(front->val)+',';

            q.push(front->left);
            q.push(front->right);
        }
       
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if (data == "#") return NULL;

        vector<string> nodes;
        string temp = "";

        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        if (nodes.empty() || nodes[0] == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (i < nodes.size() && nodes[i] != "#") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "#") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
