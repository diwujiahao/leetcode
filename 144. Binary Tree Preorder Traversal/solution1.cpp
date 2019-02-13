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
    
    void recursion(TreeNode* node){
        if (!node){
            return;
        }
        result.push_back(node->val);
        recursion(node->left);
        recursion(node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        recursion(root);
        return result;
    }
};