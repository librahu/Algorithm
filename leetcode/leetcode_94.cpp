/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * recursively
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
         vector<int> res;
         helper(res, root);
         return res;
     }

     void helper(vector<int>& res, TreeNode* root){
       if(!root) return;

       helper(res, root->left);
       res.push_back(root->val);
       helper(res, root->right);
     }
};

/**
 * iteratively
 */
class Solution{
public:
   vector<int> inorderTraversal(TreeNode* root){
     vector<int> res;
     stack<TreeNode*> s;

     if(!root) return res;

     while(!s.empty()||root){
       if(root){
         s.push(root);
         root = root->left;
       }
       else{
         root = s.top();
         s.pop();
         res.push_back(root->val);
         root = root->right;
       }
     }
     return res;
   }
};
