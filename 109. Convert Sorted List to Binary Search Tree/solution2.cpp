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
    
    ListNode* node; // 全局节点指针
    
    // 计算链表元素个数
    int find_size(ListNode* point){
        int count = 0;
        while(point){
            count++;
            point = point->next;
        }
        return count;
    }
    
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
        temp_node->val = node->val;
        node = node->next;
        // 建立右子树
        temp_node->right = recursion(mid + 1, right);
        return temp_node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        node = head;
        int len = find_size(head);
        return recursion(0, len - 1);
    }
};