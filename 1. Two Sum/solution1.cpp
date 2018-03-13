class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        for (int l = 0; l < nums.size() - 1; l++){
            for (int r = l + 1; r < nums.size(); r++){
                if (nums[l] + nums[r] == target){
                    return {l,r};
                }
            }
        }
        return {0,0};
    }
};