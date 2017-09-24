/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    -- 从上向下搜索, 遇到p或q或null, return之
    -- 回溯过程中, (1).左return != null且右return != null (即左p右q或左q右p), 说明current root是LCA, return之;
                  (2).左右谁不为null就向上return谁 (即p或q, 或null).
*/ 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root) 
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left!=NULL && right!=NULL)
            return root;
        
        return left!=NULL ? left : right;
        
    }
};
