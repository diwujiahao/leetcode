// quick sort

class Solution {
    ListNode* partition(ListNode* begin, ListNode* end){
        ListNode* mid = begin;
        ListNode* current = begin;
        ListNode* point = begin->next;
        while (point && point != end){
            if (point->val < mid->val){
                current = current->next;
                swap(point->val, current->val);
            }
            point = point->next;
        }
        swap(begin->val, current->val);
        return current;
    }
    
    void sort(ListNode* begin, ListNode* end){
        if (!begin || begin == end || begin->next == end){
            return;
        }
        ListNode* mid = partition(begin, end);
        sort(begin, mid);
        sort(mid->next, end);
    }
public:
    ListNode* sortList(ListNode* head) {
        // 定义begin和end
        ListNode *begin = head, *end = nullptr;
        sort(begin, end);
        return head;
    }
};