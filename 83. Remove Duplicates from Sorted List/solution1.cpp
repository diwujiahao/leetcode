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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *point = head, *last_point = nullptr;
        while (point){
            // 当前节点与上一节点相同
            if (last_point && point->val == last_point->val){
                point = point->next;
                last_point->next = point;
            }
            // 当前节点与上一节点不相同/上一节点不存在
            else{
                last_point = point;
                point = point->next;
            }
        }
        return head;
    }
};