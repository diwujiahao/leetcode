/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int result;
    void recursion(TreeNode* node, int &k){
        if (!node)
            return;
        recursion(node->left, k);
        k--;
        if (k == 0)
            result = node->val;
        recursion(node->right, k);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        recursion(root, k);
        return result;
    }
};