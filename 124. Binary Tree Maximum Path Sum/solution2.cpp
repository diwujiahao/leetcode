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
    
    int result = INT_MIN;

    int recursion(TreeNode* node){
        // 到达空节点
        if (!node){
            return 0;
        }
        // 递归计算以当前定点为转折点的路径和
        int left = max(0, recursion(node->left));
        int right = max(0, recursion(node->right));
        result = max(result, left + right + node->val);
        return max(left, right) + node->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        recursion(root);
        return result;
    }
};