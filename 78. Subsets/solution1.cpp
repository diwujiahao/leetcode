class Solution {
    vector<vector<int>> result;
    void recursion(vector<int> temp, int begin, vector<int> nums){
        //到达叶子节点
        if (nums.size() == 0){
            return;
        }
        result.push_back(temp);
        //递归
        for (int i = begin; i < nums.size(); i++){
            temp.push_back(nums[i]);
            recursion(temp, i+1, nums);
            temp.erase(temp.begin() + temp.size() - 1);
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        recursion(temp, 0, nums);
        return result;
    }
};