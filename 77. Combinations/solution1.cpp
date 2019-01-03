class Solution {
    vector<vector<int>> result;
    void recursion(vector<int> temp, int begin, int end, int k){
        //到达叶子节点
        if (k == 0){
            result.push_back(temp);
            return;
        }
        //不可能情况剪枝
        if (end - begin + 1 < k){
            return;
        }
        //递归
        for (int i = begin; i <= end; i++){
            temp.push_back(i);
            recursion(temp, i+1, end, k-1);
            temp.erase(temp.begin() + temp.size() - 1);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        recursion(temp, 1, n, k);
        return result;
    }
};
