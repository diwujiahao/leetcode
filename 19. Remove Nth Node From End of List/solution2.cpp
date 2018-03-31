class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node;
        ListNode *temp = head;
        int count = 0;
        while (temp){
            node.push_back(temp);
            count++;
            temp = temp->next;
        }
        int delete_num = count - n - 1;
        if (n == count)//删除第一个节点
            return (count == 1)? nullptr : head->next;
        else if (n == 1)//删除最后一个节点
            node[delete_num]->next = nullptr;
        else//删除中间节点
            node[delete_num]->next = node[delete_num]->next->next;
        return head;
    }
};