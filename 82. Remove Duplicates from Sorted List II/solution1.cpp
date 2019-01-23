/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    // 删除从point开始的连续重复数字
    // point 指向第一个重复数字
    // last_point 指向point的上一个节点（若point为头结点，则last_point为空）
    // point 移动向第一个不重复的节点（即将与last_point拼接的节点）
    ListNode* delete_node(ListNode* point, ListNode* last_point){
        while (point->next && point->val == point->next->val){
            point = point->next;
        }
        // 删除本段重复数字
        point = point->next;
        if (last_point){
            last_point->next = point;
        }
        return point;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* point = head;
        ListNode* last_point = nullptr;
        while (point && point->next){
            // 如果从point出现重复
            if (point->val == point->next->val){
                point = delete_node(point, last_point);
                // 若重复从头结点开始，更新头结点。
                if (!last_point){
                    head = point;
                }
            }
            // point节点未出现重复
            else{
                last_point = point;
                point = point->next;
            }
        }
        return head;
    }
};