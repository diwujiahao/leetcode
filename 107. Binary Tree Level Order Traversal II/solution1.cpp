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
    deque<vector<int>> result;
    queue<TreeNode*> line;
    int count = 0;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //特殊情况判断
        if (!root){
            return vector<vector<int>>(result.begin(), result.end());
        }
        // 加入头结点
        line.push(root);
        while(!line.empty()){
            // 换行判断
            if (count == 0){
                count = line.size();
                result.push_front(vector<int>());
            }
            // 取出一个节点
            TreeNode* temp_node = line.front();
            line.pop();
            count--;
            result.front().push_back(temp_node->val);
            // 压入子节点
            if (temp_node->left){
                line.push(temp_node->left);
            }
            if (temp_node->right){
                line.push(temp_node->right);
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};