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
    void recursion(TreeNode* node, int depth){
        if (!node){
            return;
        }
        if (depth >= result.size()){
            result.push_back(node->val);
        }
        recursion(node->right, depth+1);
        recursion(node->left, depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        recursion(root, 0);
        return result;
    }
};