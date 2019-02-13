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
    
    vector<vector<int>> result;
    int target;
    
    void recursion(TreeNode* node, vector<int> temp, int temp_sum){
        // 空节点返回
        if (!node){
            return;
        }
        // 加入当前节点值
        temp.push_back(node->val);
        temp_sum += node->val;
        // 判断当前路径是否满足条件
        if (temp_sum == target && !node->left && !node->right){
            result.push_back(temp);
        }
        // 遍历左右子树
        recursion(node->left, temp, temp_sum);
        recursion(node->right, temp, temp_sum);
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        target = sum;
        recursion(root, vector<int>(), 0);
        return result;
    }
};