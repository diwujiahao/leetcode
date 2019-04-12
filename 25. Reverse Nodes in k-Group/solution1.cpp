class Solution {
    
    // 从prehead的下一个节点开始，翻转k个节点
    ListNode* reverse(ListNode* prehead, int k){
        vector<ListNode*> data;
        ListNode* point = prehead;
        k = k + 1;
        while(k > 0 && point){
            data.push_back(point);
            point = point->next;
            k--;
        }
        // 剩余元素不足k个
        if (k > 0){
            return nullptr;
        }
        data.push_back(point);
        
        int left = 1, right = int(data.size()) - 2;
        while (left < right){
            swap_node(data, left++, right--);
        }
        return data[int(data.size()) - 2];
    }
    
    // 交换data中的left和right节点
    void swap_node(vector<ListNode*> &data, int left, int right){
        data[left-1]->next = data[right];
        data[left]->next = data[right+1];
        if (right - left == 1){
            data[right]->next = data[left];
        }
        else{
            data[right]->next = data[left+1];
            data[right-1]->next = data[left];
        }
        swap(data[left], data[right]);
        
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* point = prehead;
        while (point){
            point = reverse(point, k);
        }
        return prehead->next;
    }
};