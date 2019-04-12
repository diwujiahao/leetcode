class Solution {
    
    ListNode *result;
    
    ListNode* recursion(ListNode* node){
        if (!node->next){
            result = node;
            return node;
        }
        ListNode* next_node = recursion(node->next);
        next_node->next = node;
        return node;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        if (!head){
            return head;
        }
        recursion(head);
        head->next = nullptr;
        return result;
    }
};