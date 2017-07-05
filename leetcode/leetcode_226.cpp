/**
 * recursively
 */
class Solution{
public:
   TreeNode* invertTree(TreeNode* root){
     if(!root) return NULL;

     TreeNode* left = root->left;
     TreeNode* right = root->right;

     //recursive step
     root->left = invertTree(right);
     root->right = invertTree(left);
     return root;
   }
};

/**
 * based on bfs
 */
class Solution{
public:
  TreeNode* invertTree(TreeNode* root){
    if(!root) return NULL;

    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
      TreeNode* cur = Q.front();
      Q.pop();
      //invert child node
      TreeNode* tmp = cur->left;
      cur->left = cur->right;
      cur->right = tmp;

      if(cur->left)
        Q.push(cur->left);
      if(cur->right)
        Q.push(cur->right);
    }
    return root;
  }
};
