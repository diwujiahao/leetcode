/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    // 获取链表长度
    int getLength(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    
    // 翻转链表前半部分
    pair<ListNode*, ListNode*> reverse(ListNode* head, int length){
        int length_half = length / 2;
        ListNode *last = nullptr, *current = head, *next = head->next;
        while(length_half--){
            current->next = last;
            last = current;
            current = next;
            next = next->next;
        }
        if (length % 2 == 0)
            return make_pair(last, current);    
        else
            return make_pair(last, next);
    }
    
public:
    bool isPalindrome(ListNode* head) {
        // 获取链表长度
        int length = getLength(head);
        if (length < 2)
            return true;
        if (length == 2)
            return head->val == head->next->val;
        // 翻转链表前半部分
        pair<ListNode*, ListNode*> point = reverse(head, length);
        // 判断回文
        while (point.first && point.second){
            if (point.first->val != point.second->val)
                return false;
            point.first = point.first->next;
            point.second = point.second->next;
        }
        return true;
    }
};