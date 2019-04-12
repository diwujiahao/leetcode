class Solution {
    // 赋值nums的begin到end
    vector<int> copy_vec(vector<int> nums, int begin, int end){
        vector<int> temp;
        for (int i = begin; i <= end; i++){
            temp.push_back(nums[i]);
        }
        return temp;
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> left = copy_vec(nums, 0, nums.size()-k-1);
        vector<int> right = copy_vec(nums, nums.size()-k, nums.size()-1);
        right.insert(right.end(), left.begin(), left.end());
        nums = copy_vec(right, 0, right.size()-1);
    }
};