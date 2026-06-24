/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
             if(root == nullptr){
                return nullptr;
             }
             
             if(root == p || root == q){
                return root ;
             }

             TreeNode* leftnode = lowestCommonAncestor(root->left,p,q);
             TreeNode* rightnode = lowestCommonAncestor(root->right,p,q);

             if(leftnode == nullptr && rightnode != nullptr){
                return rightnode;
             }
             else if(leftnode != nullptr && rightnode == nullptr){
                return leftnode ;
             }
             else if(leftnode != nullptr && rightnode != nullptr){
                return root ;
             }
             else{
                return nullptr ;
             }
    }
};
