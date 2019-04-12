
class MERGE{
    vector<int> aux;
    
    // 将left-mid和mid-right原地归并
    void merge(vector<int> &a, int left, int mid, int right){
        int i = left; // 前半部分指针
        int j = mid + 1; // 后半部分指针
        // 辅助数组复制
        for (int k = left; k <= right; k++){
            aux[k] = a[k];
        }
        // 归并（将aux归并至a）
        for (int k = left; k <= right; k++){
            if (i > mid)
                a[k] = aux[j++];
            else if (j > right)
                a[k] = aux[i++];
            else if (aux[i] <= aux[j])
                a[k] = aux[i++];
            else
                a[k] = aux[j++];
        }
        return;
    }
    
    // 将a从left-right排序
    void sort(vector<int> &a, int left, int right){
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        sort(a, left, mid);
        sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
    
public:
    
    void sort_vector(vector<int> &a){
        // 辅助空间初始化
        aux = vector<int>(a.size(), 0);
        // 归并排序
        sort(a, 0, int(a.size())-1);
    }
    
};



class MERGE{
    
    // 将left-mid和mid-right原地归并
    void merge(ListNode* head1, ListNode* head2){
        ListNode* prehead = ListNode(0), point = prehead;
        while (head1 && head2){
            if (head1->val <= head2->val){
                point->next = head1;
                head1 = head1->next;
            }
            else{
                point->next = head2;
                head2 = head2->next;
            }
            point = point->next;
        }
        if (head1){
            point->next = head1;
        }
        if (head2){
            point->next = head2;
        }
        return prehead->next;
    }
    
    // 将a从left-right排序
    ListNode* sort(ListNode* head){
        if (!head || !head->next){
            return head;
        }
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = nullptr;
    
        return merge(sort(head1), sort(head2));
    }
    
public:
    
    void sort_vector(ListNode* head){
        // 归并排序
        sort(ListNode* head);
    }
    
};