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
    
    bool judge(TreeNode* node, long long low, long long high){
        // 如果到达叶子节点的子节点，返回
        if (!node){
            return true;
        }
        // 检查当前节点范围是否正确
        if (node->val <= low || node->val >= high ){
            return false;
        }
        // 检查左子树
        if (node->left && !judge(node->left, low, node->val)){
            return false;
        }
        // 检查右子树
        if (node->right && !judge(node->right, node->val, high)){
            return false;
        }
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return judge(root, LONG_MIN, LONG_MAX);
    }
};