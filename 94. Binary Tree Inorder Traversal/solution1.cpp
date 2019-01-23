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
    void recursion(TreeNode *node){
        if (!node){
            return;
        }
        if (node->left){
            recursion(node->left);
        }
        result.push_back(node->val);
        if (node->right){
            recursion(node->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        recursion(root);
        return result;
    }
};