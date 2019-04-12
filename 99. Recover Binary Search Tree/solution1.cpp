/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 交换两个元素，中序遍历就不是递增序列了，通过逆序寻找交换的节点

class Solution {
    TreeNode *node1 = nullptr, *node2 = nullptr;
    
    TreeNode* last_node = nullptr;
    
    // 中序遍历
    void recursion(TreeNode* node){
        if (!node){
            return;
        }
        recursion(node->left);
        if (last_node && node->val < last_node->val){
            if (!node1){
                node1 = last_node;
                node2 = node; // 防止相邻元素交换的情况
            }
            else{
                node2 = node;
            }
        }
        last_node = node;
        recursion(node->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        recursion(root);
        swap(node1->val, node2->val);
        return;
    }
};