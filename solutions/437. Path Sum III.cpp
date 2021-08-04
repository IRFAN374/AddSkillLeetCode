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
    int ans= 0;
        
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return ans;
        pathFind(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
    void  pathFind(TreeNode *root,int targetSum,int currSum){
        if(root==NULL) return;
        currSum +=root->val;
        if(currSum==targetSum) ans++;
        pathFind(root->left,targetSum,currSum);
        pathFind(root->right,targetSum,currSum);
    }
};
