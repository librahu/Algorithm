/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//BFS 
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* cur = new TreeNode(v);
            cur->left = root;
            return cur;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        d --;
        
        TreeNode* cur, *tmp_left, *tmp_right;
        while(!Q.empty() && d){
            int size =  Q.size();
            for(int i = 0; i < size; i++){
                cur = Q.front();
                Q.pop();
                
                if(d > 1){
                    if(cur->left) Q.push(cur->left);
                    if(cur->right) Q.push(cur->right);
                }
                else{
                    tmp_left = new TreeNode(v);
                    tmp_right = new TreeNode(v);
                    
                    tmp_left->left = cur->left;
                    tmp_right->right = cur->right;
                    
                    cur->left = tmp_left;
                    cur->right = tmp_right;
                }
            }
            d--;
        }
        return root;
    }
};

//DFS
class Solution {
public:
    void addOneRowR(TreeNode* root, int v, int d, int cd) {
        if (!root) return;
        
        if (cd == d) {
            TreeNode *savLeft = root->left;
            root->left = new TreeNode(v);
            root->left->left = savLeft;
            
            TreeNode *savRight = root->right;
            root->right = new TreeNode(v);
            root->right->right = savRight;
            return;
        }
        addOneRowR(root->left, v, d, cd + 1);
        addOneRowR(root->right, v, d, cd + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        addOneRowR(root, v, d, 2);
        return root;
    }
}; 
