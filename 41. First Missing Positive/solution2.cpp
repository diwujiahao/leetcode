class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 将1-nums.size范围的数字放到自己的位置上
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 碰到第一个位置上不是自己的元素返回索引
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i + 1){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};