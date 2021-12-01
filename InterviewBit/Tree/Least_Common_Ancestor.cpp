/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void count(TreeNode* A,int &cnt,int b,int c)
{ if(A==NULL) return;
   if(A->val==b) cnt++;
   if(A->val==c) cnt++;
   count(A->left,cnt,b,c);
   count(A->right,cnt,b,c);

}
int LCA(TreeNode *root,int b,int c)
{ if(root==NULL) return -1;
  
  if(root->val==b) return b;
  if(root->val==c) return c;

  int lft=LCA(root->left,b,c);
  int rgt=LCA(root->right,b,c);
  if(lft!=-1 && rgt!=-1)
    return root->val;
  else if(lft!=-1)
    return lft;
  return rgt;
   


}
int Solution::lca(TreeNode* A, int B, int C) {
    int cnt=0;
    count(A,cnt,B,C);
    if(cnt!=2)
     return -1;
    int ans=LCA(A,B,C);
    return ans;
}
