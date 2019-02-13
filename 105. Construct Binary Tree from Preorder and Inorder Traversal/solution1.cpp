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
    int find_mid(vector<int> data, int left, int right, int target){
        for (int i = left; i <= right; i++){
            if (data[i] == target){
                return i;
            }
        }
        return 0;
    }
    
    TreeNode* recursion(vector<int> preorder, int pre_left, int pre_right, vector<int> inorder, int in_left, int in_right){
        // 到达根节点
        if (pre_left > pre_right || in_left > in_right){
            return nullptr;
        }
        // 寻找并建立当前节点
        int mid_index = find_mid(inorder, in_left, in_right, preorder[pre_left]);
        TreeNode* node = new TreeNode(preorder[pre_left]);
        // 递归建立左右子树
        node->left = recursion(preorder, pre_left+1, pre_left+(mid_index-in_left), inorder, in_left, mid_index-1);
        node->right = recursion(preorder, pre_left+(mid_index-in_left)+1, pre_right, inorder, mid_index+1, in_right);
        // 返回当前节点
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursion(preorder, 0, int(preorder.size())-1, inorder, 0, int(inorder.size())-1);
    }
};



// 哈希结构代替中序节点的查找
// 减少时间复杂度
class Solution {
    unordered_map<int, int> map;
    
    TreeNode* recursion(vector<int> preorder, int pre_left, int pre_right, vector<int> inorder, int in_left, int in_right){
        // 到达根节点
        if (pre_left > pre_right || in_left > in_right){
            return nullptr;
        }
        int mid_index = map[preorder[pre_left]];
        TreeNode* node = new TreeNode(preorder[pre_left]);
        node->left = recursion(preorder, pre_left+1, pre_left+(mid_index-in_left), inorder, in_left, mid_index-1);
        node->right = recursion(preorder, pre_left+(mid_index-in_left)+1, pre_right, inorder, mid_index+1, in_right);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return recursion(preorder, 0, int(preorder.size())-1, inorder, 0, int(inorder.size())-1);
    }
};
