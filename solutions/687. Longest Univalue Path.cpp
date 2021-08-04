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
    int maxlen =INT_MIN;
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root,root->val);
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return maxlen-1;
    }
    int helper(TreeNode *root, int target){
        if(root==NULL) return 0;
        if(root->val !=target) return 0;
        int lmax = 1+helper(root->left, target);
        int rmax = 1+ helper(root->right,target);
        maxlen = max({
            lmax, rmax, maxlen, lmax+rmax-1
        });
        return max({lmax,rmax});
    }
};
