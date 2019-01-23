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
    bool recursion(TreeNode* p_node, TreeNode* q_node){
        // 全为空
        if (!p_node && !q_node){
            return true;
        }
        // 全不为空
        else if (p_node && q_node){
            // 检查两个节点值是否一样
            if (p_node->val != q_node->val){
                return false;
            }
            // 检查子节点
            return recursion(p_node->left, q_node->left) && recursion(p_node->right, q_node->right);
        }
        // 一个节点为空
        else{
            return false;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recursion(p, q);
    }
};