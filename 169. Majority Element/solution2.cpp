class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (int i : nums){
            // i 已经出现过
            if (hash.find(i) != hash.end()){
                hash[i]++;
            }
            // i 第一次出现
            else{
                hash[i] = 1;
            }
            if (hash[i] > nums.size() / 2){
                return i;
            }
        }
        return 0;
    }
};