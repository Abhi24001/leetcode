class Solution {
    vector<int> answer;
public:
    vector<int> inorderTraversal(TreeNode* root) {

        inorderTraversalHelper(root);
        return answer;        
    }

    void inorderTraversalHelper(TreeNode * root){
        if(!root) return;
        inorderTraversalHelper(root->left);
        answer.push_back(root->val);
        inorderTraversalHelper(root->right);
    }
};
