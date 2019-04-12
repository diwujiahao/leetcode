// 集合存储
// 需要空间复杂度
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> data;
        for (int num : nums){
            if (data.find(num) != data.end()){
                return true;
            }
            data.insert(num);
        }
        return false;
    }
};