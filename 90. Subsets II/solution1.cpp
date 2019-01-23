class Solution {
    // 标记nums第i位是否使用
    vector<bool> label;
    // 存储结果
    vector<vector<int>> result;

    void recursion(vector<int> nums, vector<int> temp, int index){
        // 添加一个结果
        result.push_back(temp);
        // 从之前取到的最后一个元素开始遍历
        for (int i = index; i < nums.size(); i++){
            // 当前第i位元素没有使用
            if (label[i] == false){
                // 避免重复元素导致集合重复
                if (i > 0 && nums[i-1] == nums[i] && label[i-1] == false){
                    continue;
                }
                // 添加元素i，并递归
                label[i] = true;
                temp.push_back(nums[i]);
                recursion(nums, temp, i+1);
                label[i] = false;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 排序
        sort(nums.begin(), nums.end());
        // 初始化label标记
        label = vector<bool>(nums.size(), false);
        // 调用递归函数
        recursion(nums, vector<int>(0), 0);
        // 返回结果
        return result;
    }
};