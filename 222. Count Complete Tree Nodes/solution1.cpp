/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 层次遍历统计节点个数
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count_node = 0;
        queue<TreeNode*> data;
        if (root){
            data.push(root);
        }
        while (!data.empty()){
            TreeNode* temp = data.front();
            data.pop();
            count_node++;
            if (temp->left){
                data.push(temp->left);
            }
            if (temp->right){
                data.push(temp->right);
            }
        }
        return count_node;
    }
};




// 正常遍历就可以
class Solution {
    int count_node = 0;
    
    void get_count_node(TreeNode* node){
        if (!node){
            return;
        }
        count_node++;
        get_count_node(node->left);
        get_count_node(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        get_count_node(root);
        return count_node;
    }
};
