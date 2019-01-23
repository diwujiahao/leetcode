/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// {1,2,3,4,5}, m=2, n=4
// begin=1, end=5

class Solution {
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //特殊情况判断
        if (!head || !head->next){
            return head;
        }
        // 新增头节点head_before
        // 定位begin和end
        ListNode *head_before = new ListNode(0);
        head_before->next = head;
        ListNode *begin = head_before, *end = head_before;
        while(m-- > 1){
            begin = begin->next;
        }
        while(n-- > -1){
            end = end->next;
        }
        // 开始反转
        ListNode *last = (begin->next) ? begin->next : nullptr;
        ListNode *current = (begin->next->next) ? begin->next->next : nullptr;
        while(current != end){
            ListNode* next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        // 反转包含头节点
        if (begin->val == 0){
            head = last;
            begin->next->next = end;
        }
        // 反转不包含头节点
        else{
            begin->next->next = end;
            begin->next = last;
        }
        
        
        return head;
    }
};