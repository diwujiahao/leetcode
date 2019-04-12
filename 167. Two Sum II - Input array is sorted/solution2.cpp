class Solution {
    unordered_map<int, int> data;
    // data[i] = j
    // 表示 numbers[j] + i = target
    // 即第 j 个元素缺 i
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++){
            if (data.find(numbers[i]) != data.end()){
                return {data[numbers[i]]+1, i+1};
            }
            data[target - numbers[i]] = i;
        }
        return {};
    }
};