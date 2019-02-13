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
    void reorderList(ListNode* head) {
        if (!head){
            return;
        }
        // 将链表存入data中（vector格式）
        vector<ListNode*> data;
        ListNode* point = head;
        while (point){
            data.push_back(point);
            point = point->next;
        }
        // 在data中重新操作链表顺序，左右交替指向
        int left = 0, right = int(data.size()) - 1;
        bool label = true;
        while (left < right){
            // 左
            if (label){
                data[left]->next = data[right];
                left++;
            }
            // 右
            else{
                data[right]->next = data[left];
                right--;
            }
            label = !label;
        }
        data[left]->next = nullptr;
    }
};