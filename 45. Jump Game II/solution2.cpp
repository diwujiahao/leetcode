// left~right 是当前 step 的起跳新范围
// 每个循环step+1，并更新 left~right范围

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0;
        int step = 0;
        while (right < nums.size() - 1){
            step++;
            int temp_max = right;
            for (int i = left; i <= right; i++){
                temp_max = max(temp_max, i + nums[i]);
            }
            if (temp_max >= nums.size() - 1){
                return step;
            }
            left = right + 1;
            right = temp_max;
        }
        return step;
    }
};