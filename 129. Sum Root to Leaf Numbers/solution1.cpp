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
    int result = 0;
    
    void recursion(TreeNode* node, int temp){
        // 空节点
        if (!node){
            return;
        }
        // 叶子节点
        if (!node->left && !node->right){
            result += temp * 10 + node->val;
            return;
        }
        // 非叶子节点
        recursion(node->left, temp * 10 + node->val);
        recursion(node->right, temp * 10 + node->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        recursion(root, 0);
        return result;
    }
};