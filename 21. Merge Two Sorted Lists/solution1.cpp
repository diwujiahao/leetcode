class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0), *point = result;
        while (l1 && l2){
            if (l1->val > l2->val){
                point->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else{
                point->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            point = point->next;
        }
        while(l1){
            point->next = new ListNode(l1->val);
            l1 = l1->next;
            point = point->next;
        }
        while(l2){
            point->next = new ListNode(l2->val);
            l2 = l2->next;
            point = point->next;
        }
        return result->next;
    }
};