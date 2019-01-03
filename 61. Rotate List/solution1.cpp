class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //特殊情况判断
        if (!head){
            return head;
        }
        //统计链表长度 更新k值
        int length = 0;
        ListNode *point = head;
        while(point){
            length++;
            point = point->next;
        }
        k = k % length;
        //开始修改
        //head：初始头结点
        //tail：初始尾节点
        //last：新头结点
        //next：新尾节点
        point = head;
        ListNode *last = nullptr, *next = nullptr, *tail = nullptr;
        while(point){
            length--;
            if (length == k){
                last = point;
                next = point->next;
            }
            if (length == 0){
                tail = point;
                //k = 0 时 修正next指针
                if (!next){
                    next = head;
                }
            }
            point = point->next;
        }
        tail->next = head;
        last->next = nullptr;
        return next;
    }
};