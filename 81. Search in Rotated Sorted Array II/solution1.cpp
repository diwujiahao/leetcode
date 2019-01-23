class Solution {
    // 二分查找转折点
    // 由于需要和右指针比大小，右指针始终保持在右半边（最小值及其右边）
    int search_pivot(vector<int> nums){
        int left = 0, right = int(nums.size()) - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]){
                // 保证右指针始终保持在右半边（最小值及其右边）
                // 没有加一
                right = mid;
            }
            else if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                // 保证右指针始终保持在右半边（最小值及其右边）
                // 进行判断，如果找到转折点则返回
                if (nums[right] >= nums[right - 1]){
                    right--;
                }
                else{
                    return right;
                }
            }
        }
        return left;
    }
    // 二分搜索
    bool binary_search(vector<int> nums, int begin, int end, int target){
        while(begin <= end){
            int mid = (begin + end) / 2;
            if (nums[mid] < target){
                begin = mid + 1;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return false;
        }
        // 查找到旋转点
        int pivot = search_pivot(nums);
        // 根据旋转点二分搜索
        if (pivot == 0){
            return binary_search(nums, 0, int(nums.size())-1, target);
        }
        else if (target > nums[0]){
            return binary_search(nums, 0, pivot-1, target);
        }
        else if (target < nums[0]){
            return binary_search(nums, pivot, int(nums.size())-1, target);
        }
        else{
            return true;
        }
    }
};