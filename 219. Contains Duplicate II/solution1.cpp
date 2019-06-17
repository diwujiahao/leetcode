class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++){
            // nums[i]出现过
            if (hash.find(nums[i]) != hash.end()){
                if (i - hash[nums[i]] <= k){
                    return true;
                }
                else{
                    hash[nums[i]] = i;
                }
            }
            // nums[i]没出现过
            else{
                hash[nums[i]] = i;
            }
        }
        
        return false;
    }
};
