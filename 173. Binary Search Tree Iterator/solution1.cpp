class BSTIterator {
    vector<int> data;
    int point = 0;
    
    void recursion(TreeNode* node){
        if (!node){
            return;
        }
        if (node->left){
            recursion(node->left);
        }
        data.push_back(node->val);
        if (node->right){
            recursion(node->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        recursion(root);
    }
    
    /** @return the next smallest number */
    int next() {
        if (point >= data.size()){
            return 0;
        }
        return data[point++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return point < data.size();
    }
};