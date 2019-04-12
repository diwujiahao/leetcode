/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* merge(ListNode* head1, ListNode* head2){
        if (!head1){
            return head2;
        }
        if (!head2){
            return head1;
        }
        ListNode *point1 = head1, *point2 = head2, *prehead = new ListNode(0), *point = prehead;
        while (point1 && point2){
            if (point1->val <= point2->val){
                point->next = point1;
                point1 = point1->next;
            }
            else{
                point->next = point2;
                point2 = point2->next;
            }
            point = point->next;
        }
        if (point1){
            point->next = point1;
        }
        if (point2){
            point->next = point2;
        }
        return prehead->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return nullptr;
        }
        if (lists.size() == 1){
            return lists[0];
        }
        ListNode* result = nullptr;
        for (int i = 0; i < lists.size(); i++){
            result = merge(result, lists[i]);
        }
        return result;
    }
};