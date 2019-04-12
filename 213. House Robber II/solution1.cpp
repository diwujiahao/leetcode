class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        else if (nums.size() == 1){
            return nums[0];
        }
        else if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        else if (nums.size() == 3){
            return max(max(nums[0], nums[1]), nums[2]);
        }
        
        // 不取首位
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size() - 1; i++){
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        
        // 取首
        vector<int> dp_front(nums.size() - 1, 0);
        for (int i = 2; i < nums.size() - 1; i++){
            dp_front[i] = max(dp_front[i-1], dp_front[i-2] + nums[i]);
        }
        
        // 取尾
        vector<int> dp_back(nums.size() - 1, 0);
        for (int i = 1; i < nums.size() - 2; i++){
            dp_back[i+1] = max(dp_back[i], dp_back[i-1] + nums[i]);
        }
        
        return max(dp.back(), max(dp_front.back() + nums[0], dp_back.back() + nums.back()));
    }
};