/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode* recursion(vector<int> nums, int left, int right){
        if (left > right){
            return nullptr;
        }
        // 选取中值作为当前节点，保证平衡
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        // 递归建树
        node->left = recursion(nums, left, mid-1);
        node->right = recursion(nums, mid+1, right);
        // 返回当前节点
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        return recursion(nums, 0, nums.size()-1);
    }
};