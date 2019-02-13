/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* entry = head;
        ListNode* fast = head->next;
        while(fast != slow){
            if (fast == nullptr || fast->next == nullptr){
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow->next != entry) {
            slow = slow->next;
            entry = entry->next;
        }
        return entry;
    }
};