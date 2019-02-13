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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *point1 = headA, *point2 = headB;
        // 统计所有节点个数
        int count = 0;
        while (point1){
            point1 = point1->next;
            count += 2;
        }
        while (point2){
            point2 = point2->next;
            count += 2;
        }
        point1 = headA;
        point2 = headB;
        // 寻找交叉节点
        while(point1 != point2){
            point1 = (point1) ? point1->next : headB;
            point2 = (point2) ? point2->next : headA;
            count--;
            if (count < 0){
                return nullptr;
            }
        }
        return point1;
    }
};