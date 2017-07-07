/**Definition for a binary tree node.
 *struct TreeNode {
 * 	int val;
 *	TreeNode *left;
 *	TreeNode *right;
 *	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
/**
 * solution : BFS
 * time : O(n)
 * space : O(n)
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
		Q.push(root);
		int leftval;
		while(!Q.empty()){
			bool isbottom = true;
			for(int i = 0; i < Q.size(); i++){
				TreeNode* cur = Q.front();
				Q.pop();
				if(i == 0) leftval = cur->val;
				if(cur->left)	Q.push(cur->left);
				if(cur->right)	Q.push(cur->right);
			}
		}
		return leftval;
    }
};
