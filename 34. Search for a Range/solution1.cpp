class Solution {
private:
    int binary_search_l(vector<int>& nums, int target, int point_l, int point_r){
        int mid = (point_l + point_r) / 2;
        while(point_l <= point_r){
            if (nums[mid] > target)
                point_r = mid - 1;
            else if (nums[mid] < target)
                point_l = mid + 1;
            else{
                if (mid == 0 || nums[mid-1] != target)
                    return mid;
                else{
                    point_r = mid - 1;
                }
            }
            mid = (point_l + point_r) / 2;
        }
        return -1;
    }
    int binary_search_r(vector<int>& nums, int target, int point_l, int point_r){
        int mid = (point_l + point_r) / 2;
        while(point_l <= point_r){
            if (nums[mid] > target)
                point_r = mid - 1;
            else if (nums[mid] < target)
                point_l = mid + 1;
            else{
                if (mid + 1 >= nums.size() || nums[mid+1] != target)
                    return mid;
                else{
                    point_l = mid + 1;
                }
            }
            mid = (point_l + point_r) / 2;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        int l = binary_search_l(nums, target, 0, int(nums.size())-1);
        int r = binary_search_r(nums, target, l, int(nums.size())-1);
        return {l, r};
    }
};