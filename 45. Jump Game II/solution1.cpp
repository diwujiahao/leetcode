class Solution {
    vector<int> dp;
    
    int find_min(vector<int>dp, int start, int pace){
        int temp_min =  INT_MAX;
        for (int i = start + 1; i <= start + pace && i < dp.size(); i++){
            temp_min = min(temp_min, dp[i]);
        }
        return temp_min;
    }
    
public:
    int jump(vector<int>& nums) {
        dp = vector<int>(nums.size(), 0);
        for (int i = nums.size()-2; i>= 0; i--){
            int temp_min = find_min(dp, i, nums[i]);
            dp[i] = (temp_min == INT_MAX) ? INT_MAX : temp_min + 1;
        }
        return dp[0];
    }
};