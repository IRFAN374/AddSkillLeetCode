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
    int maxProduct(TreeNode* root) {
        vector<int> nums;
       
         long  ans = 0;
        int maxSum = helper(root,nums);
        for(int i=0;i<nums.size();i++){
             long  curr_prod= ((long)nums[i] * (long)(maxSum-nums[i]));
            ans = max(ans, curr_prod);
        }
        return ans%(int)(1e9 + 7);
    }
    int helper(TreeNode *root,vector<int>&nums){
        if(root==NULL) return 0;
        int lsum = helper(root->left,nums);
        int rsum = helper(root->right,nums);
        nums.push_back(root->val + lsum + rsum);
        return root->val + lsum + rsum;
    }
};
