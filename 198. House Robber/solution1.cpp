// 递归实现动态规划
// 超内存

class Solution {

    int recursion(vector<int> nums, int n){
        if (n == 0){
            return nums[0];
        }
        if (n == 1){
            return max(nums[0], nums[1]);
        }
        return max(recursion(nums, n-1), recursion(nums, n-2) + nums[n]);
    }
    
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        return recursion(nums, nums.size()-1);
    }
};