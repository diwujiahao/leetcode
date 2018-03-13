class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 =  new ListNode(0), *p3 = l3;//指针变量p3
        int carry = 0;//进位变量
        //进入循环
        while(l1 || l2 || carry){
            int number = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            //进位更新
            carry = number / 10;//进位变量更新
            number = number % 10;//新节点进位更新
            //新建节点
            p3->next = new ListNode(number);
            //指针更新
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            p3 = p3->next;
        }
        return l3->next;
    }
};