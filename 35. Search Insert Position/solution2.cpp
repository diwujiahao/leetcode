class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 特殊情况判断
        if (target < nums[0])
            return 0;
        else if (target > nums[nums.size()-1])
            return int(nums.size());
        // 定义二分查找变量
        int point_l = 0, point_r = int(nums.size()) - 1, mid = 0.5 * (point_l + point_r);
        while(point_l <= point_r){
            // 判断mid两边是否应该插入target
            if (nums[mid] < target && nums[mid + 1] > target)
                return mid + 1;
            else if (nums[mid - 1] < target && nums[mid] > target)
                return mid;
            // 二分查找
            else if (nums[mid] > target)
                point_r = mid - 1;
            else if (nums[mid] < target)
                point_l = mid + 1;
            else
                return mid;
            mid = 0.5 * (point_l + point_r);
        }
        return -1;
    }
};