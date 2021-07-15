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
    bool isValidBST(TreeNode* root) {
        long long int minVal = LONG_MIN;
        long long int maxVal = LONG_MAX;
        
        return checkBST(root,minVal,maxVal);
    }
    bool checkBST(TreeNode *root,long long int minVal,long long int maxVal){
      if(root==NULL) return true;
      bool leftTrue = (root->val < maxVal ) && checkBST(root->left,minVal, root->val);
      bool rightTrue = (root->val > minVal) && checkBST(root->right, root->val , maxVal);
      return (leftTrue && rightTrue);
    }
};
