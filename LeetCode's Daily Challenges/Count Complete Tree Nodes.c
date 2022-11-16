void count_nodes(struct TreeNode* root, int* size){
    if(root==NULL){
        *size=0;
        return;
    }
    int l_subtree_size, r_subtree_size;  
    count_nodes(root->left, &l_subtree_size);
    count_nodes(root->right, &r_subtree_size);
    *size=l_subtree_size+r_subtree_size+1;
}

int countNodes(struct TreeNode* root){
    int size=0;
    count_nodes(root, &size);
    return size;
}
