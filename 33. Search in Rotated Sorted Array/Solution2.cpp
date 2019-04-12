// 二分搜索变形题

class Solution {
    
    int binary_search(vector<int> nums, int target){
        int left = 0, right = int(nums.size()) - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            // 查看是否结束搜索
            if (nums[mid] == target){
                return mid;
            }
            // mid~right 有序
            if (nums[mid] < nums[right]){
                // target 在 mid~right 有序范围内
                if (target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            // left~mid 有序
            else{
                // target 在 left~mid 有序范围内
                if (target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }

        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target);
    }
};