/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 利用两个栈来实现后序遍历
// s2栈，存储后序遍历的逆序

class Solution {
    stack<TreeNode*> s1;
    stack<int> s2;
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root){
            return result;
        }
        s1.push(root);
        while(!s1.empty()){
            // 取出栈顶元素
            TreeNode* temp = s1.top();
            s1.pop();
            // 当前元素放入s2
            s2.push(temp->val);
            // 左右节点放入s1
            if (temp->left){
                s1.push(temp->left);
            }
            if (temp->right){
                s1.push(temp->right);
            }
        }
        // 将s2元素倒序
        while(!s2.empty()){
            result.push_back(s2.top());
            s2.pop();
        }
        return result;
    }
};