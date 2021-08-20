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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()){
            int size = q.size();
            TreeNode *temp=NULL;
            for(int i=0;i<size;i++){
                temp=q.front();
                q.pop();
                if(i==0) ans = temp->val;
                if(temp->left!=NULL)  q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
        return ans;
    }
};