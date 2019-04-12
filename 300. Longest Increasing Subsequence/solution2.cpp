// 将已经遍历过得元素维护称为有序队列（元素可以顶替掉）

// input: [0, 8, 4, 12, 2]
// dp: [0]
// dp: [0, 8]
// dp: [0, 4]
// dp: [0, 4, 12]
// dp: [0 , 2, 12]

class Solution {
    
    int binary_search(vector<int> nums, int left, int right, int target){
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] > target){
                right = mid - 1;
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return left;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++){
            int index = binary_search(dp, 0, result, nums[i]);
            dp[index] = nums[i];
            if (index == result){
                result++;
            }
        }
        
        return result;
    }
};
