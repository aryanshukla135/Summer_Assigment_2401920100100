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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result ;
        if(root == nullptr){
            return result ;
        }
        queue<TreeNode*> q ;
        q.push(root);
        bool flip = true;

        while(!q.empty()){
            int n= q.size();
            vector<int> temp(n);

            for(int i =0 ; i< n ; i++){
                TreeNode* front = q.front();
                q.pop();

                int idx = flip ? i : n-i-1;
                temp[idx] = front->val;

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            flip = !flip;
            result.push_back(temp);
        }
        return result ;
    }
};
