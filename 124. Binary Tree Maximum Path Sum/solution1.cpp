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
    // 存储结果
    int result = INT_MIN;
    // 寻找四个值中的最大值
    int find_max(int n, int n_l, int n_r, int n_l_r = INT_MIN){
        int label = INT_MIN;
        label = max(label, n);
        label = max(label, n_l);
        label = max(label, n_r);
        label = max(label, n_l_r);
        return label;
    }
    // 递归函数
    int recursion(TreeNode* node){
        // 到达空节点
        if (!node){
            return 0;
        }
        // 递归计算以当前定点为转折点的路径和
        int left = recursion(node->left);
        int right = recursion(node->right);
        // 计算  路过  当前节点的最大路径和，查看是否更新result
        result = max(result, find_max(node->val, left + node->val, right + node->val, left + right + node->val));
        // 返回当前节点  出发  的最大路径和
        return find_max(node->val, left + node->val, right + node->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        recursion(root);
        return result;
    }
};
