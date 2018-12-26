class Solution {
private:
    set<vector<int>> result;
    vector<int> label;
    
    void recursion(vector<int>nums, vector<int> temp){
        if (temp.size() == nums.size()){
            result.insert(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (label[i] == 0){
                label[i] = 1;
                temp.push_back(nums[i]);
                recursion(nums, temp);
                temp.pop_back();
                label[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 初始化使用情况
        label.resize(nums.size(), 0);
        vector<int> temp;
        recursion(nums, temp);
        
        vector<vector<int>> result_convert;
        result_convert.assign(result.begin(), result.end());
        return result_convert;
    }
};
