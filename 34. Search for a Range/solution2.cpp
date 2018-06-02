class Solution {
private:
    vector<int> binary_search(vector<int>& nums, int target, int point_l, int point_r){
        int mid = (point_l + point_r) / 2;
        while(point_l <= point_r){
            if (nums[mid] > target)
                point_r = mid - 1;
            else if (nums[mid] < target)
                point_l = mid + 1;
            else{
                int l = mid, r = mid;
                while(l != 0 && nums[l-1] == target)
                    l--;
                while(l != int(nums.size())-1 && nums[r+1] == target)
                    r++;
                return {l, r};
            }
            mid = (point_l + point_r) / 2;
        }
        return {-1, -1};
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        return binary_search(nums, target, 0, int(nums.size())-1);
    }
};