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
    vector<string> result;
    
    void recursion(string temp, TreeNode* node){
        // 空节点返回
        if (!node){
            return ;
        }
        // 添加当前路径
        temp += (temp.size() == 0) ? to_string(node->val) : "->" + to_string(node->val);
        // 当前节点为叶子节点--加入一个结果
        if (!node->left && !node->right){
            result.push_back(temp);
        }
        // 递归遍历
        recursion(temp, node->left);
        recursion(temp, node->right);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        recursion("", root);
        return result;
    }
};