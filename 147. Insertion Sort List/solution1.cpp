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
    ListNode* insertionSortList(ListNode* head) {
        if (!head){
            return head;
        }
        // 制造无用头结点
        ListNode* prehead = new ListNode(INT_MIN);
        prehead->next = head;
        
        ListNode* point = head, *last = prehead, *next_p = head->next;
        while(point){
            // 寻找插入点insert_index
            ListNode* insert_index = prehead;
            while(insert_index->next != point && insert_index->next->val <= point->val){
                insert_index = insert_index->next;
            }
            // point节点不需要移动
            if (insert_index->next == point){
                last = point;
                point = point->next;
                next_p = (point) ? point->next : nullptr;
            }
            // point节点需要插入在insert_insert后
            else{
                point->next = insert_index->next;
                insert_index->next = point;
                last->next = next_p;
                point = next_p;
                next_p = (point) ? point->next : nullptr;
            }
        }
        return prehead->next;
    }
};