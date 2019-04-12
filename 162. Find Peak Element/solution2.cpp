// 二分搜索变形题

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            int mid = (left + right) / 2;
            // 峰值在右边
            if (nums[mid] < nums[mid+1]){
                left = mid + 1;
            }
            // 峰值在左边，mid也有可能是峰值
            else{
                right = mid;
            }
        }
        return left;
    }
};