class Solution {
private:
    vector<vector<int>> result; // 结果存储
    vector<int> label; // 是否使用的标记
    // 递归函数
    void recursion(vector<int>nums, vector<int> temp){
        // 出现完整排列 - 加入结果队列并返回
        if (temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        // 排列不完整 - 继续加入元素
        for (int i = 0; i < nums.size(); i++){
            // 元素i已经被使用过 - 跳过
            if (label[i] == 1){
                continue;
            }
            // 重复元素已经被使用过 - 跳过
            if (i > 0 && label[i-1] == 0 && nums[i] == nums[i-1] ){
                continue;
            }
            // 加入元素i进入下一轮迭代
            label[i] = 1;
            temp.push_back(nums[i]);
            recursion(nums, temp);
            temp.pop_back();
            label[i] = 0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 初始化使用情况
        label.resize(nums.size(), 0);
        vector<int> temp;
        // 排序
        sort(nums.begin(), nums.end());
        // 递归迭代
        recursion(nums, temp);
        return result;
    }
};
