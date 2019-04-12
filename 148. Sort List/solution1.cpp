// merge sort

class Solution {
    
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* prehead = new ListNode(0), *point = prehead;
        while(head1 && head2){
            if (head1->val <= head2->val){
                point->next = head1;
                head1 = head1->next;
            }
            else{
                point->next = head2;
                head2 = head2->next;
            }
            point = point->next;
        }
        if (head1){
            point->next = head1;
        }
        if (head2){
            point->next = head2;
        }
        return prehead->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        // 如果已经拆成单个元素，则返回
        if (!head || !head->next){
            return head;
        }
        // 否则进行二分
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = nullptr;
        // 递归调用二分后的两个链表
        return merge(sortList(head1), sortList(head2));
    }
};