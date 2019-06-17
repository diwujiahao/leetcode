class Solution {
    unordered_map<int, int> hash;
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        for (int i : nums){
            // 当前数字i出现过
            if (hash.find(i) != hash.end()){
                hash[i] += 1;
            }
            // 当前数字i未出现过
            else{
                hash[i] = 1;
            }
        }
        
        for (auto i : hash){
            if (i.second > nums.size()/3){
                result.push_back(i.first);
            }
        }
        return result;
    }
};