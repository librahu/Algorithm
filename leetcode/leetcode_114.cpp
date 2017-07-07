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
* divide & conquer
* time :O(n)
* space : O(n)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
  		if(root == NULL) return ;
		flatten(root->left);
		flatten(root->right);
		if(root->left == NULL) return;
		TreeNode* cur = root->left;
		while(cur->right) cur = cur->right;
		cur->right = root->right; 
		root->right = root->left;     
    }
};
