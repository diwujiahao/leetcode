class Solution {
    bool result = false;
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] == 0){
                int temp_index = i;
                while(temp_index--){
                    if (nums[temp_index] + temp_index > i){
                        break;
                    }
                }
                if (temp_index < 0){
                    return false;
                }
            }
        }
        return true;
    }
};