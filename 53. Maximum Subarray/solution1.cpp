class Solution {
    vector<int> dp;
    int max_num = INT_MIN;
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        //初始化
        dp.resize(nums.size(), 0);
        dp[0] = nums[0];
        max_num = max(max_num, dp[0]);
        //循环
        for (int i = 1 ; i < nums.size(); i++){
            //使用之前的求和
            if (dp[i-1] > 0){
                dp[i] = dp[i-1] + nums[i];
            }
            //不使用之前的求和
            else{
                dp[i] = nums[i];
            }
            max_num = max(max_num, dp[i]);
        }
        //返回结果
        return max_num;
    }
};