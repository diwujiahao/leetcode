// 利用栈来存储节点信息
// 指针lcp来存储已经访问到的节点与当前访问节点的最近公共祖先


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
    TreeNode* lcp = nullptr;
    stack<pair<TreeNode*, int>> data;
    // 0:左右子节点均未访问
    // 1:左节点已经访问
    // 2:左右节点均已经访问
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        data.push(make_pair(root, 0));
        
        while (!data.empty()){
            if (!data.top().first){
                data.pop();
            }
            if (data.top().second == 0 && (data.top().first == p || data.top().first == q)){
                if (lcp){
                    return lcp;
                }
                lcp = data.top().first;
            }
            // 栈顶节点-左右子节点均未访问
            if (data.top().second == 0){
                data.top().second = 1;
                data.push(make_pair(data.top().first->left, 0));
            }
            // 栈顶节点-左节点已经访问
            else if (data.top().second == 1){
                data.top().second = 2;
                data.push(make_pair(data.top().first->right, 0));
            }
            // 栈顶节点-左右节点均已经访问
            else{
                TreeNode* temp = data.top().first;
                data.pop();
                if (lcp && temp == lcp){
                    lcp = data.top().first;
                }
            }
        }
        
        return nullptr;
    }
};
