class Solution {
private:
    // 存放结果变量
    vector<vector<int>> result;
    // vector 求和函数
    int get_sum(vector<int> road){
        int output = 0;
        for (int i : road)
            output += i;
        return output;
    }
    // 递归函数
    //candidates:候选数字
    //target:求和目标值
    //road:当前选取的候选数字
    //label:当前选取候选数字最大的下标（为了不出现重复而设置）
    void recursion(vector<int>& candidates, int target, vector<int> road, int label){
        // 越界剪枝
        if (get_sum(road) > target){
            return;
        }
        // 找到一个可行解 保存后返回（继续搜索一定越界）
        else if (get_sum(road) == target){
            result.push_back(road);
            return;
        }
        // 未找到可行解，继续搜索
        else{
            for (int i = label + 1; i < candidates.size(); i++){
                int i_ = i;
                while (i+1 < candidates.size() && candidates[i+1] == candidates[i]){
                    i++;
                }
                vector<int> road_ = road;
                for (int j = i_; j <= i; j++){
                    road_.push_back(candidates[j]);
                    recursion(candidates, target, road_, i);
                }
            }
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> road;
        sort(candidates.begin(), candidates.end());
        recursion(candidates, target, road, -1);
        return result;
    }
};