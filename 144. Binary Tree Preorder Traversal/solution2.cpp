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
    vector<int> result;
    stack<TreeNode*> data;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root){
            return result;
        }
        data.push(root);
        while(!data.empty()){
            // 去除栈顶元素
            TreeNode* temp = data.top();
            data.pop();
            // 先序遍历
            result.push_back(temp->val);
            // 入栈
            if (temp->right){
                data.push(temp->right);
            }
            if (temp->left){
                data.push(temp->left);
            }
        }
        return result;
    }
};