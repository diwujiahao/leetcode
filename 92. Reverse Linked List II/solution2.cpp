class Solution {
    ListNode* left;
    bool stop_label = false;
    
    void reverse(ListNode *right, int n){
        // 停止递归移动右指针
        if (n < 1){
            return;
        }
        // 递归
        reverse(right->next, n-1);
        // 交换
        if (left == right || left == right->next){
            stop_label = true;
        }
        if (stop_label){
            return;
        }
        swap(left->val, right->val);
        left = left->next;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        left = head;
        while(m-- > 1){
            left = left->next;
        }
        reverse(head, n);
        return head;
    }
};