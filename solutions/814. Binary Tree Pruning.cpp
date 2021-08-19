/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool ans = helper(root);
        if(ans) return NULL;
        return root;
    }
    bool helper(TreeNode *root){
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL){
            if(root->val == 0) return true;
            else return false;
        }
        bool lbool = helper(root->left);
        if(lbool) root->left=NULL;
        bool rbool = helper(root->right);
        if(rbool) root->right=NULL;
        return (lbool && rbool && root->val==0);
    }
};
