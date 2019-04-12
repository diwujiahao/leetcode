class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> result(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for (int i = nums.size()-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for (int i = 0; i < nums.size(); i++){
            result[i] = left[i] * right[i];
        }
        return result;
    }
};



// 空间复杂度 O（1）不计算返回值
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int temp = 1;
        for (int i  = nums.size()-2; i >= 0; i--){
            temp *= nums[i+1];
            result[i] = result[i] * temp;
        }
        return result;
    }
};