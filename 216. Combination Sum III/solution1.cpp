// 回溯思路
class Solution {
    
    vector<vector<int>> result;
    
    void recursion(vector<int> temp, int k, int n){
        // 判出条件
        if (temp.size() >= k){
            if (accumulate(temp.begin(), temp.end(), 0) == n){
                result.push_back(temp);
            }
            return;
        }
        // 回溯
        for (int i = (temp.size() == 0) ? 1 : temp.back()+1; i < 10; i++){
            temp.push_back(i);
            recursion(temp, k, n);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        recursion(vector<int>(), k, n);
        return result;
    }
};
