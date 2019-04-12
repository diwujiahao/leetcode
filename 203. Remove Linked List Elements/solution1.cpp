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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prehead = new ListNode(0);
        prehead->next = head;
        ListNode *point = prehead;
        
        while (point->next){
            if (point->next->val == val){
                point->next = point->next->next;
            }
            else{
                point = point->next;
            }
            
        }
        return prehead->next;
    }
};