// 空间复杂度超出限制

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // dp[i][j] 表示从i到j的求和结果
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        int result = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++){
            dp[i][i] = nums[i];
        }
        
        for (int i = nums.size()-1; i >= 0; i--){
            for (int j = i; j < nums.size(); j++){
                dp[i][j] = dp[i+1][j] + nums[i];
                if (dp[i][j] >= s){
                    result = min(result, j-i+1);
                }
            }
        }
        
        return result == INT_MAX ? 0 : result;
        
    }
};