class Solution {
    unordered_map<int, int> hash;
public:
    int singleNumber(vector<int>& nums) {
        // 构造哈希表
        for (auto i : nums){
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
            }
            else{
                hash[i]++;
            }
        }
        // 选出只有一个的元素
        for (auto i : hash){
            if (i.second == 1){
                return i.first;
            }
        }
        return 0;
    }
};