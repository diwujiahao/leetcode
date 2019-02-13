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
    bool label = true;
    
    int recursion(TreeNode* node){
        if (!node){
            return 0;
        }
        int left = recursion(node->left);
        int right = recursion(node->right);
        if (abs(left - right) > 1){
            label = false;
        }
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        recursion(root);
        return label;
    }
};