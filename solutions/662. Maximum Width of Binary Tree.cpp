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
    int widthOfBinaryTree(TreeNode* root) {
      queue<pair<TreeNode*,int>>q;
      q.push(make_pair(root,1));
      
      pair<TreeNode*,int> temp;
      int maxWidth =1;
      
      while(!q.empty()){
        int count = q.size();
        int startPosition = q.front().second;
        int endPosition = q.back().second;
        int width = endPosition - startPosition  + 1;
        maxWidth = max(maxWidth,width);
        for(int i=0;i<count;i++){
          temp = q.front(); q.pop();
          int position = temp.second;
          int offPosition = position - startPosition;
          if(temp.first->left!=NULL) q.push(make_pair(temp.first->left,2*offPosition));
          if(temp.first->right!=NULL) q.push(make_pair(temp.first->right, 2*offPosition+1));
         
        }
       
      }
      return maxWidth;
    }
};
