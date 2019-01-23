  class Solution {
public:
    vector<int> grayCode(int n) {
        // 将结果数组初始化为0
        vector<int> result = {0};
        // 第i轮在右数第i位添1（相当于给数字+f）
        for (int i = 0, f = 1; i < n; i++, f<<=1){
            // 将result中现有的元素倒叙遍历，加f（高位加一）后放入result中
            for (int j = int(result.size())-1; j >= 0; j--){
                result.push_back(result[j] + f);
            }
        }
        // 返回结果
        return result;
    }
};
