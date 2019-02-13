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
    
    int recursion(TreeNode* node){
        // 非叶子节点下的空节点，不能当做最下层的节点
        if (!node){
            return INT_MAX;
        }
        // 当前节点为叶子节点
        if (!node->left && !node->right){
            return 1;
        }
        // 递归计算左右子树的深度
        int left = recursion(node->left);
        int right = recursion(node->right);
        // 返回左右子树较小的深度+1
        return min(left, right) + 1;
    }
    
public:
    int minDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        return recursion(root);   
    }
};