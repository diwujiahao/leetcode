class Solution {
private:
    vector<vector<int>> result; // 存储结果
    vector<int> label; // 使用情况
    bool all_one(vector<int> label){
        for (int i : label)
            if (i == 0)
                return false;
        return true;
    }
    // 递归函数
    void recursion(vector<int> nums, vector<int> temp){
        if (all_one(label)){
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (label[i] == 0){
                label[i] = 1;
                temp.push_back(nums[i]);
                recursion(nums, temp);
                label[i] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 初始化使用情况
        label.resize(nums.size(), 0);
        vector<int> temp;
        recursion(nums, temp);
        return result;
    }
};