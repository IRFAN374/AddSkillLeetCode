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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int right = nums.size();
        int left = 0;
        return helper(nums,left,right);
    }
    TreeNode *helper(vector<int>&nums,int left,int right){
        if(left==right) return NULL;
        int maxIndex = helpermax(nums,left,right);
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = helper(nums,left,maxIndex);
        root->right = helper(nums,maxIndex+1,right);
        return root;
    }
    int helpermax(vector<int>&nums,int left,int right){
        int index = left;
        for(int i=left;i<right;i++){
            if(nums[i]>nums[index]){
                index=i;
            }
