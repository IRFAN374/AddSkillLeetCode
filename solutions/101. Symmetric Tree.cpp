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
    bool isSymmetric(TreeNode* root) {
      if(root==NULL) return true;  
      return checkSymmetric(root,root);
    }
    
    bool checkSymmetric(TreeNode *rootLeft,TreeNode *rootRight){
      if(rootLeft==NULL && rootRight==NULL) return true;
      if(rootLeft==NULL || rootRight==NULL) return false;
      return ( (rootLeft->val == rootRight->val) && checkSymmetric(rootLeft->left,rootRight->right) && checkSymmetric(rootLeft->right,rootRight->left));
    }
};
