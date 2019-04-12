// 改进了链表的翻转

class Solution {
    
    ListNode* reverse(ListNode* prehead, int k){
        ListNode* return_point = nullptr;
        if (!check(prehead, k)){
            return return_point;
        }
        ListNode* point = prehead->next;
        ListNode* next = point->next;
        while (k-- > 1){
            if (!next){
                return nullptr;
            }
            ListNode* new_point = next;
            ListNode* new_next = next->next;
            next->next = point;
            point = new_point;
            next = new_next;
        }
        return_point = prehead->next;
        prehead->next->next = next;
        prehead->next = point;
        return return_point;
    }

    bool check(ListNode* prehead, int k){
        while(k--){
            prehead = prehead->next;
            if (!prehead){
                return false;
            }
        }
        return true;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* point = prehead;
        while (point){
            point = reverse(point, k);
        }
        return prehead->next;
    }
};
