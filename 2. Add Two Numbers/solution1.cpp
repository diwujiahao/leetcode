class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 =  new ListNode(0), *p1 = l1, *p2 = l2, *p3 = l3;//指针变量p1/p2/p3
        p3->val = p1->val + p2->val;
        int carry = (p3->val > 9) ? 1 : 0;//进位变量
        p3->val = (p3->val > 9) ? p3->val - 10 : p3->val;
        p1 = p1->next;
        p2 = p2->next;
        while(p1 && p2){
            p3->next = new ListNode(p1->val + p2->val + carry);//新建节点
            //进位更新
            p3 = p3->next;
            carry = (p3->val > 9) ? 1 : 0;//进位变量更新
            p3->val = (p3->val > 9) ? p3->val - 10 : p3->val;//新节点进位更新
            //指针更新
            p1 = p1->next;
            p2 = p2->next;
        }
        //l1还没完
        if (p1){
            p3->next = p1;
            //进位更新
            while(carry){
                if (p3->next)
                    p3->next->val += carry;
                else
                    p3->next = new ListNode(carry);
                p3 = p3->next;
                carry = (p3->val > 9) ? 1 : 0;//进位变量更新
                p3->val = (p3->val > 9) ? p3->val - 10 : p3->val;//新节点进位更新
            }
        }
        //l2还没完
        else if (p2){
            p3->next = p2;
            //进位更新
            while(carry){
                if (p3->next)
                    p3->next->val += carry;
                else
                    p3->next = new ListNode(carry);
                p3 = p3->next;
                carry = (p3->val > 9) ? 1 : 0;//进位变量更新
                p3->val = (p3->val > 9) ? p3->val - 10 : p3->val;//新节点进位更新
            }
        }
        //都完了
        else{
            //进位更新
            while(carry){
                p3->next = new ListNode(carry);
                p3 = p3->next;
                carry = (p3->val > 9) ? 1 : 0;//进位变量更新
                p3->val = (p3->val > 9) ? p3->val - 10 : p3->val;//新节点进位更新
            }
        }
        return l3;
    }
};
