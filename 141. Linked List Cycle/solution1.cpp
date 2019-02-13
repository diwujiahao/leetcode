/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    set<ListNode*> data;
public:
    bool hasCycle(ListNode *head) {
        while(head){
            data.insert(head);
            head = head->next;
            if (data.find(head) != data.end()){
                return true;
                break;
            }
        }
        return false;
    }
};