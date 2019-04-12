// 快排的修改版本

class Solution {
    
    int partition(vector<int> &nums, int left, int right){
        int temp = nums[left];
        int i = left, j = right+1;
        while(1){
            while (nums[++i] < temp){
                if (i >= right){
                    break;
                }
            }
            while (nums[--j] > temp){
                if (j <= left){
                    break;
                }
            }
            if (i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        return j;
    }  
    
    int sort(vector<int> &nums, int k, int left, int right){
        if (left >= right){
            return nums[left];
        }
        int mid = partition(nums, left, right);
        if (nums.size() - mid > k){
            return sort(nums, k, mid+1, right);
        }
        else if (nums.size() - mid < k){
            return sort(nums, k, left, mid-1);
        }
        else{
            return nums[mid];
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return sort(nums, k, 0, nums.size()-1);
    }
};





class Solution {
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int sort(vector<int> &nums, int k, int left, int right){
        if (left >= right){
            return nums[left];
        }
        int mid = partition(nums, left, right);
        if (mid+1 < k){
            return sort(nums, k, mid+1, right);
        }
        else if (mid+1 > k){
            return sort(nums, k, left, mid-1);
        }
        else{
            return nums[mid];
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return sort(nums, k, 0, nums.size()-1);
    }
};
