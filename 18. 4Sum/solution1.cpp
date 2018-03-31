class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;//返回值
        //特殊情况判断
        if (nums.size() < 4)
            return result;
        //排序
        sort(nums.begin(), nums.end());
        //循环两个数/查找另两个数
        for (int i = 0; i < nums.size()-3; i++){
            for (int j = i + 1; j < nums.size()-2; j++){
                int temp = nums[i] + nums[j];
                //最大情况仍不够target/继续j的循环
                if (temp + nums[nums.size()-1] * 2 < target)
                    continue;
                //最小情况仍超过target/跳过j的循环
                else if (temp + nums[j + 1] * 2 > target)
                    break;
                else{
                    int left = j + 1, right = int(nums.size()) - 1;
                    while(left < right){
                        //left+right大了/减小right
                        if (temp + nums[left] + nums[right] > target)
                            right--;
                        //left+right小了/增大left
                        else if(temp + nums[left] + nums[right] < target)
                            left++;
                        //找到一个组合
                        else{
                            result.push_back({nums[i],nums[j],nums[left],nums[right]});
                            //跳过相同数字
                            while(result.back()[2] == nums[left])   left++;
                            while(result.back()[3] == nums[right])  right--;
                        }
                    }
                }
                //跳过相同数字
                int temp_j = j;
                while(j + 1 < nums.size() && nums[temp_j] == nums[j + 1])   j++;
            }
            //跳过相同数字
            int temp_i = i;
            while(i + 1 < nums.size() && nums[temp_i] == nums[i + 1])   i++;
        }
        return result;
    }
};