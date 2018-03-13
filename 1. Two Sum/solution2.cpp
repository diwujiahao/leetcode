class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        vector<vector<int>> nums_plus;
        for (int i = 0; i < nums.size(); i++){
            nums_plus.push_back({nums[i],i});
        }
        sort(nums_plus.begin(), nums_plus.end());
        int l = 0, r = int(nums_plus.size()) - 1;
        while(l < r){
            if(nums_plus[l][0] + nums_plus[r][0] > target){
                r--;
            }
            else if(nums_plus[l][0] + nums_plus[r][0] < target){
                l++;
            }
            else{
                return {nums_plus[l][1],nums_plus[r][1]};
            }
        }
        return {0,0};
    }
};