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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = nullptr, *after = nullptr, *point_b = nullptr, *point_a = nullptr;
        ListNode *point = head;
        while (point){
            // 当前节点值小于x, 将x插入before末尾
            if (point->val < x){
                // 列表暂时为空
                if (!point_b){
                    before = new ListNode(point->val);
                    point_b = before;
                }
                // 列表不为空
                else{
                    point_b->next = new ListNode(point->val);
                    point_b = point_b->next;
                }
            }
            // 当前节点值大于等于x, 将x插入after末尾
            else{
                // 列表暂时为空
                if (!point_a){
                    after = new ListNode(point->val);
                    point_a = after;
                }
                // 列表不为空
                else{
                    point_a->next = new ListNode(point->val);
                    point_a = point_a->next;
                }
            }
            point = point->next;
        }
        // 返回结果
        if (!point_b){
            return after;
        }
        point_b->next = after;
        return before;
        
    }
};