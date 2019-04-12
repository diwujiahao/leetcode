// 利用了 198. House Robber 动态规划的思想（dp_rob1）

class Solution {
    
    int dp_rob1(vector<int> nums, int left, int right){
        vector<int> dp(right-left+3, 0);
        for (int i = 0; i <= right-left; i++){
            dp[i+2] = max(dp[i+1], dp[i] + nums[i+left]);
        }
        return dp.back();
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 3){
            int result = 0;
            for (int i : nums){
                result = max(result, i);
            }
            return result;
        }
        
        int rob = dp_rob1(nums, 1, int(nums.size())-2);
        int rob_front = dp_rob1(nums, 2, int(nums.size())-2);
        int rob_back = dp_rob1(nums, 1, int(nums.size())-3);
        
        return max(rob, max(rob_front + nums[0], rob_back + nums.back()));
    }
};



// 2 7 9 3 1
//     9 3   = rob_front + 2
//   7 9     = rob_back + 1
//   7 9 3   = rob

// 取最大值