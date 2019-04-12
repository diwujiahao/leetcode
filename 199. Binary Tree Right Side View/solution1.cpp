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
    queue<TreeNode*> data;
    int count = 0;
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root){
            return result;
        }
        data.push(root);
        while(!data.empty()){
            // 判断是否换层
            if (count == 0){
                count = data.size();
            }
            // 取一个节点
            TreeNode* temp = data.front();
            data.pop();
            count--;
            // 判断是否为当前层最右
            if (count == 0){
                result.push_back(temp->val);
            }
            // 左右子节点加入队列
            if (temp->left){
                data.push(temp->left);
            }
            if (temp->right){
                data.push(temp->right);
            }
        }
        return result;
    }
};