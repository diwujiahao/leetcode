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
    bool recursion(TreeNode* node_l, TreeNode* node_r){
        // 两个节点均为空
        if (!node_l && !node_r){
            return true;
        }
        // 两个节点均非空
        else if (node_l && node_r){
            // 检查两个节点值是否一样
            if (node_l->val != node_r->val){
                return false;
            }
            // 检查子节点
            return recursion(node_l->left, node_r->right) && recursion(node_l->right, node_r->left);
        }
        // 其中一个节点为空
        else{
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        // 特殊情况判断
        if (!root){
            return true;
        }
        return recursion(root->left, root->right);
    }
};
