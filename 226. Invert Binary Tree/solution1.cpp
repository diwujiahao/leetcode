/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归方法
class Solution { 
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root){
            return nullptr;
        }
        TreeNode* node_left = root->left;
        TreeNode* node_right = root->right;
        root->left = invertTree(node_right);
        root->right = invertTree(node_left);
        return root;
    }
};




// 迭代方法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root){
            return root;
        }
        queue<TreeNode*> data;
        data.push(root);
        while(!data.empty()){
            TreeNode* temp = data.front();
            data.pop();
            TreeNode* node_left = temp->left;
            temp->left = temp->right;
            temp->right = node_left;
            if (temp->left)
                data.push(temp->left);
            if (temp->right)
                data.push(temp->right);
        }
        
        return root;
    }
};