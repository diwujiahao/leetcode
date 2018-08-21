class Solution {
private:
    // 存放结果变量
    vector<vector<int>> result;
    // 递归函数
    //candidates:候选数字
    //target:求和目标值
    //road:当前选取的候选数字
    //label:当前选取候选数字最大的下标（为了不出现重复而设置）
    void recursion(vector<int>& candidates, int target, vector<int> road, int label){
        // 找到可行解
        if (target == 0)
            result.push_back(road);
        // 未找到可行解，继续搜索
        else{
            // 进入下一层递归
            for (int i = label; i < candidates.size() && candidates[i] <= target; i++){
                // 跳过重复项
                if (i != label && candidates[i-1] == candidates[i])
                    continue;
                // 递归
                road.push_back(candidates[i]);
                recursion(candidates, target-candidates[i], road, i+1);
                road.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> road;
        vector<vector<int> > ret;
        recursion(candidates, target, road, 0);
        return result;
    }
};
