/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    set<ListNode*> set1;
    set<ListNode*> set2;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *point1 = headA, *point2 = headB;
        while(point1 || point2){
            // 当前节点相交
            if (point1 == point2){
                return point1;
            }
            // 检查之前的交点
            if (point1){
                if (set2.find(point1) != set2.end()){
                    return point1;
                }
                set1.insert(point1);
                point1 = point1->next;
            }
            if (point2){
                if (set1.find(point2) != set1.end()){
                    return point2;
                }
                set2.insert(point2);
                point2 = point2->next;
            }
        }
        return nullptr;
    }
};