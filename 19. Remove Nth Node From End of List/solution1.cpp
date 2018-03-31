class Solution {
private:
    //统计链表长度函数
    int count_list(ListNode* head){
        int count = 0;
        while (head){
            head = head->next;
            count++;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        //统计链表长度
        int count = count_list(head);
        //特殊情况判断
        if (n == 1 && count == 1)//特殊情况:链表长度为1
            return nullptr;
        else if (count == n)//特殊情况:删除第一个节点
            return head->next;
        else{//正常情况删除
            //将temp移至待删除节点前一个
            count = count - n - 1;
            temp = head;
            while(count-- > 0)
                temp = temp->next;
            //删除节点
            if (n == 1)//特殊情况:删除第最后一个节点
                temp->next = nullptr;
            else//正常情况删除节点
                temp->next = temp->next->next;
        }
        return head;
    }
};