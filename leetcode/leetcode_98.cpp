/**Definition for a binary tree node.
 * struct TreeNode {
 *    int val;
 *    TreeNode *left;
 *    TreeNode *right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 */
/**
 * Solution : DFS, inorder traversal
 * time : o(n)
 * space : o(n)
 */
class Solution {
public:
    TreeNode* lastNode = NULL;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(!isValidBST(root->left)) return false;
        if(lastNode && root->val <= lastNode->val) return false;
        lastNode = root;
        return isValidBST(root->right);
    }
};

class Solution {
	bool isValidBST(TreeNode* root) {
		if(root == NULL) return true;
		
	}
}

