class Solution {
private:
    // 二分寻找pivot点
    int find_pivot(vector<int>& nums, int point_l, int point_r){
        int mid = (point_l + point_r) / 2;
        // 开始二分循环
        while (point_l <= point_r){
            // mid指向0
            if (mid - 1 < 0)
                if (mid + 1 < int(nums.size()))
                    return (nums[mid] > nums[mid + 1]) ? mid + 1 : -1;//pivot可能在1
                else
                    return -1;//nums只有一个元素
            // mid即为pivot点
            else if (nums[mid] < nums[mid-1])
                return mid;
            // pivot点在右半边
            else if (nums[mid] > nums[0])
                point_l = mid + 1;
            // pivot点在左半边
            else if (nums[mid] < nums[0])
                point_r = mid - 1;
            //更新mid
            mid = (point_l + point_r) / 2;
        }
        return -1;
    }
    // 二分查找
    int binary_search(vector<int>& nums, int target, int point_l, int point_r){
        int mid = (point_l + point_r) / 2;
        while(point_l <= point_r){
            if (nums[mid] > target)
                point_r = mid - 1;
            else if (nums[mid] < target)
                point_l = mid + 1;
            else
                return mid;
            mid = (point_l + point_r) / 2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        // 寻找pivot点
        int pivot = find_pivot(nums, 0, int(nums.size()-1));
        // 没有pivot
        if (pivot == -1)
            return binary_search(nums, target, 0, int(nums.size()-1));
        // 目标在前段
        else if (target >= nums[0])
            return binary_search(nums, target, 0, pivot - 1);
        // 目标在后段
        else
            return binary_search(nums, target, pivot, int(nums.size()-1));
    }
};