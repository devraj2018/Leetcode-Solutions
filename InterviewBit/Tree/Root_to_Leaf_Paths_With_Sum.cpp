/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
   void util(TreeNode* A,int sum, vector<int>curr_path,vector<vector<int>>&final_path,int curr_sum)
    {    if(A==NULL)
         return;
         curr_sum+= A->val;
          curr_path.push_back(A->val);
         if(A->left==NULL && A->right==NULL && curr_sum==sum)
              final_path.push_back(curr_path);
        util(A->left,sum,curr_path,final_path,curr_sum);
        util(A->right,sum,curr_path,final_path,curr_sum);
    }
    vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
          vector<vector<int>> final_path;
           vector<int> curr_path;
           int curr_sum=0;
           util(A,B,curr_path,final_path,curr_sum);
          return final_path;
      }
