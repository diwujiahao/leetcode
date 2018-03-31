class Solution {
private:
    //交换函数
    //待交换的节点分别为(node->next, node->next->next)
    bool swap(ListNode *node){
        //检查node之后两个节点是否存在
        if (node->next && node->next->next){
            ListNode *temp = node->next;//临时节点
            //开始交换
            node->next = temp->next;
            temp->next = temp->next->next;
            node->next->next = temp;
            return true;
        }
        else
            return false;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        //制造头结点/方便循环
        ListNode *result = new ListNode(0), *point = result;
        result->next = head;
        //开始循环
        while(swap(point))
            point = point->next->next;
        return result->next;
    }
};