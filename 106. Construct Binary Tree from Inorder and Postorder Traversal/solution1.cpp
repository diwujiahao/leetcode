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
    
    unordered_map<int, int> inorder_map;
    
    TreeNode* recursion(vector<int> inorder, int in_left, int in_right, vector<int> postorder, int post_left, int post_right){
        if (in_left > in_right || post_left > post_right){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[post_right]);
        int mid_index = inorder_map[postorder[post_right]];
        node->left = recursion(inorder, in_left, mid_index-1, postorder, post_left, post_left + (mid_index - in_left) - 1);
        node->right = recursion(inorder, mid_index+1, in_right, postorder, post_left + (mid_index - in_left), post_right - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        TreeNode* result =  recursion(inorder, 0, int(inorder.size())-1, postorder, 0, int(postorder.size())-1);
        return result;
    }
};