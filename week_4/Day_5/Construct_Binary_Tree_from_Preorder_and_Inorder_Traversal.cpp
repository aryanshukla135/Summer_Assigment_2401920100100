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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index , int inorderstrt,int inorderend,int n ,unordered_map<int,int> &m){
        if(index>=n || inorderstrt>inorderend){
            return nullptr ;
        }
        int val = preorder[index++];
        TreeNode* root = new TreeNode(val);
        int pos = m[val];

        root->left = solve(preorder,inorder,index,inorderstrt,pos-1,n,m);
        root->right = solve(preorder,inorder,index,pos+1,inorderend,n,m);

        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int index =0;
        int inorderstrt =0;
        int inorderend = n-1;
      
        unordered_map<int,int> m ;
        for(int i =0 ; i<n ; i++){
            m[inorder[i]]=i;
        }
        TreeNode* ans =solve(preorder,inorder,index,inorderstrt,inorderend,n,m);

        return ans ;
    }
};
