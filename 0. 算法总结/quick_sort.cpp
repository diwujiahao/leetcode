class QUICKSORT{
    
    // 将数组切分为left-i、i、i+1-right
    int partition(vector<int> &a, int left, int right){
        int v = a[left]; // 切分元素
        int i = left; // 切分指针
        int j = right+1; // 切分指针
        while (true){
            while (a[++i] < v){
                if (i == right){
                    break;
                }
            }
            while (a[--j] > v){
                if (j == left){
                    break;
                }
            }
            if (i >= j){
                break;
            }
            swap(a[i], a[j]);
        }
        swap(a[j], a[left]);
        return j;
    }
    
    // int partition(vector<int>& nums, int left, int right) {
    //      int pivot = nums[left], l = left + 1, r = right;
    //      while (l <= r) {
    //          if (nums[l] > pivot && nums[r] < pivot) {
    //              swap(nums[l++], nums[r--]);
    //          }
    //          if (nums[l] <= pivot) {
    //              l++;
    //          }
    //          if (nums[r] >= pivot) {
    //              r--;
    //          }
    //      }
    //      swap(nums[left], nums[r]);
    //      return r;
    //  }
    
    void sort(vector<int> &a, int left, int right){
        if (left >= right)
            return;
        int j = partition(a, left, right);
        sort(a, left, j-1);
        sort(a, j+1, right);
    }
    
public:
    void sort_vector(vector<int> &a){
        // 可以加入打乱顺序代码-消除对输入特点的依赖
        sort(a, 0, int(a.size()) - 1);
    }
};




class QUICKSORT{
    
    // 将数组切分为begin、mid、end
    ListNode* partition(ListNode* begin, ListNode* end){
        ListNode* current = begin;
        ListNode* point = begin->next;
        while (point && point != end){
            if (point->val <= begin->val){
                current = current->next;
                swap(point->val, current->val);
            }
            point = point->next;
        }
        swap(left->val, current->val);
        return current;
    }
    
    void sort(ListNode* begin, ListNode* end){
        if (!begin || begin == end || !begin->next || begin->next == end){
            return;
        }
        ListNode* mid = partition(begin, end);
        sort(begin, mid);
        sort(mid->next, end);
    }
    
public:
    ListNode sort_vector(ListNode* head){
        // 可以加入打乱顺序代码-消除对输入特点的依赖
        ListNode* begin = head; 
        ListNode* end = nullptr;
        sort(begin, end);
    }
};

















