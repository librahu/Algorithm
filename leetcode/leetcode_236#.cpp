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
    -- ������������, ����p��q��null, return֮
    -- ���ݹ�����, (1).��return != null����return != null (����p��q����q��p), ˵��current root��LCA, return֮;
                  (2).����˭��Ϊnull������return˭ (��p��q, ��null).
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
