// 代码超时


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
    
    vector<TreeNode*> get_path(vector<TreeNode*> path, TreeNode* node, TreeNode* target){
        if (!node){
            return vector<TreeNode*>();
        }
        path.push_back(node);
        // 当前节点是目标--返回路径
        if (node == target){
            return path;
        }
        // 当前节点不是目标--继续向下寻找
        else{
            vector<TreeNode*> left_result = get_path(path, node->left, target);
            if (left_result.size() > 0)
                return left_result;
            vector<TreeNode*> right_result = get_path(path, node->right, target);
            if (right_result.size() > 0)
                return right_result;
        }
        return vector<TreeNode*>();
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_1 = get_path(vector<TreeNode*>(), root, p);
        vector<TreeNode*> path_2 = get_path(vector<TreeNode*>(), root, q);
        unordered_map<TreeNode*, int> hash;
        for (int i = int(path_1.size())-1; i >= 0; i--){
            hash[path_1[i]] = i;
        }
        for (int i = int(path_2.size())-1; i >= 0; i--){
            if (hash.find(path_2[i]) != hash.end()){
                return path_2[i];
            }
        }
        return nullptr;
    }
};

