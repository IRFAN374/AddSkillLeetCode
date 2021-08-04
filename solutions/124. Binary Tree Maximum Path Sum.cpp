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
    int maxValue = INT_MIN;
    int maxPathSum(TreeNode* root) {
        
        helper(root);
        return maxValue;
    }
    int helper(TreeNode *root){
        if(root==NULL) return 0;
        
        int l_max = root->val+helper(root->left);
        int r_max = root->val+helper(root->right);
        maxValue = max({l_max,r_max,l_max+r_max-root->val,maxValue,root->val});
        return max({l_max,r_max,root->val});
    }
};
