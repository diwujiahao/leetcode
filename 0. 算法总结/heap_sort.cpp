class HEAPSORT{
    
    // 上浮操作
    void swim(vector<int> &a, int begin, int end){
        int k = end;
        while (k > 1 && a[k/2] < a[k]){
            swap(a[k], a[k/2]);
            k = k / 2;
        }
    }
    
    // 下沉操作
    void sink(vector<int> &a, int begin, int end){
        int k = begin; // 待下沉头结点
        while (2*k <= end){
            int j = 2*k;
            if (j < end && a[j] < a[j+1]){
                j++;
            }
            if (a[k] >= a[j]){
                break;
            }
            swap(a[k], a[j]);
            k = j;
        }
    }
    
public:
    
    void sort(vector<int> &a){
        int n = int(a.size());
        // 建堆-跳过叶子节点
        // 下沉建堆比上浮快
        for (int i = n / 2; i >= 1; i--){
            sink(a, i, n);
        }
        // 下沉排序
        while (n > 1){
            swap(a[1], a[n--]);
            sink(a, 1, n);
        }
    }
};