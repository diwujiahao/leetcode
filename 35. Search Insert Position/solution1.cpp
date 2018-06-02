class Solution {
private:
    int search(vector<int> nums, int target){
        int point_l = 0, point_r = int(nums.size()) - 1, mid = (point_l + point_r) / 2;
        while(point_r-point_l > 1){
            if (nums[mid] < target)
                point_l = mid;
            else if (nums[mid] > target)
                point_r = mid;
            else
                return mid;
            mid = (point_l + point_r) / 2;
        }
        if (nums[point_l] == target)
            return point_l;
        else if (nums[point_r] == target)
            return point_r;
        else
            return point_l + 1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || target < nums[0])
            return 0;
        if (target > nums[nums.size()-1])
            return int(nums.size());
        return search(nums, target);
    }
};