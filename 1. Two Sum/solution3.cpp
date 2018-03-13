class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(target - nums[i]) != hash.end())
                return {hash[target - nums[i]] + 1, i + 1};
            hash[nums[i]] = i;
        }
        return {0,0};
    }
};