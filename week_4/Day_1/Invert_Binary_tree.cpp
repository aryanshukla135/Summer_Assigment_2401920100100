/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode*root){
        if(root == nullptr){
            return ;
        }
        if(root->left==nullptr && root->right ==nullptr){
            return ;
        }
        swap(root->left,root->right);

        solve(root->left);
        solve(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
         solve(root);

         return root; 
    }
};
