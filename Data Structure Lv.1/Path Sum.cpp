class Solution {
public:
    void f(TreeNode* root, int targetSum, int contri, int &ans) {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL) {
            if(contri+root->val == targetSum) ans = 1;
            return;
        }
        
        f(root->right, targetSum, contri+root->val, ans);
        f(root->left, targetSum, contri+root->val, ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans = 0, contri = 0;
        
        f(root, targetSum, 0, ans);
        
        return ans;
    }
  };
