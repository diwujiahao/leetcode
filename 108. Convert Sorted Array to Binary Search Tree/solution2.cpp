class Solution {
    int index = 0;
    vector<int> nums_copy;
    
    // 递归建树
    // 模拟中序遍历（因为中序遍历搜索二叉树得到有序序列）
    TreeNode* recursion(int left, int right){
        if (left > right){
            return nullptr;
        }
        // 初始化根节点
        int mid = (left + right) / 2; // 选取中间节点作为当前跟节点，保证平衡
        TreeNode* temp_node = new TreeNode(0);
        // 建立左子树
        temp_node->left = recursion(left, mid - 1);
        // 建立根节点
        temp_node->val = nums_copy[index];
        index++;
        // 建立右子树
        temp_node->right = recursion(mid + 1, right);
        return temp_node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        nums_copy = nums;
        return recursion(0, nums.size()-1);
    }
    
};
