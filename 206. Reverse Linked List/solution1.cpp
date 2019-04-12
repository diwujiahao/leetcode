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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode *last = head, *current = head->next, *next = head->next->next;
        while (current){
            current->next = last;
            last = current;
            current = next;
            next = (next) ? next->next : nullptr;
        }
        head->next = nullptr;
        return last;
    }
};