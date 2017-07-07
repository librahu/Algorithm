/*Definition for a binary tree node.
 *struct TreeNode {
 *	int val;
 *	TreeNode *left;
 *	TreeNode *right;
 *	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
/**
 * sulotion : BFS
 * time : O(n)
 * space : O(n)
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if(!root) return res;
		queue<TreeNode*> Q;
		Q.push(root);
		while(!Q.empty()){
			int size = Q.size();
			vector<int> cur;
			while(size--){
				TreeNode* tmp = Q.front();
				cur.push_back(tmp->val);
				Q.pop();
				if(tmp->left)	Q.push(tmp->left);
				if(tmp->right)	Q.push(tmp->right);
			}
			res.push_back(cur);
		}
		reverse(res.begin(), res.end());
		return res;		
    }
};
