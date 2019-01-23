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

    // 递归生成子树
    vector<TreeNode*> generate(int begin, int end) {
        vector<TreeNode*> temp; // 存储本层结果
        // 到达叶子节点，返回一个null
        if (begin > end){
            return vector<TreeNode*>(1, nullptr);
        }
        // 轮流所有节点作为本节点（当前根节点）
        for (int i = begin; i <= end; i++){
            // 递归生成左右子树
            vector<TreeNode*> left = generate(begin, i-1);
            vector<TreeNode*> right = generate(i+1, end);
            // 将左右子树安装至当前节点并保存
            for (int left_index = 0; left_index < left.size(); left_index++){
                for (int right_index = 0; right_index < right.size(); right_index++){
                    TreeNode* temp_root = new TreeNode(i);
                    temp_root->left = left[left_index];
                    temp_root->right = right[right_index];
                    temp.push_back(temp_root);
                }
            }
        }
        // 返回当前根节点列表
        return temp;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        // n=0 时特殊判断
        return (n == 0) ? vector<TreeNode*>() : generate(1, n);
    }
};