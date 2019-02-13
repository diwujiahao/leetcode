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
    
    TreeNode* find_right(TreeNode* node){
        while(node->right){
            node = node->right;
        }
        return node;
    }
    
public:
    void flatten(TreeNode* root) {
        TreeNode* point = root;
        // 从root开始，向右子树遍历
        while(point){
            // 如果当前节点有左子树：
            // 1、将右子树移动到左子树的最右叶节点
            // 2、将左子树变为右子树
            // 3、将左子树置空
            if (point->left){
                // 1、将右子树移动到左子树的最右叶节点
                TreeNode* splicing = find_right(point->left);
                splicing->right = point->right;
                // 2、将左子树变为右子树
                point->right = point->left;
                // 3、将左子树置空
                point->left = nullptr;
            }
            // 移动point
            point = point->right;
        }
    }
};