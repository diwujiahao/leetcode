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
    
    int target;
    
    bool recursion(TreeNode* node, int temp){
        // 到达空节点--返回错误
        if (!node){
            return false;
        }
        // 当前求和加上当前节点的值
        temp += node->val;
        //若当前节点满足求和要求并且当前节点为叶节点--返回正确
        if (temp == target && !node->left && !node->right){
            return true;
        }
        // 若左右节点出现true，则返回true
        if (recursion(node->left, temp)){
            return true;
        }
        if (recursion(node->right, temp)){
            return true;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        target = sum;
        return recursion(root, 0);
    }
};