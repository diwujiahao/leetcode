class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        //数组排序
        sort(nums.begin(), nums.end());
        //每次确定一个数 寻找另两个数
        for (int i = 0; i < nums.size(); i++){
            //声明指针寻找定和的两个数
            int point_l = i + 1, point_r = int(nums.size() - 1);
            while (point_l < point_r){
                //进行判断
                if (nums[point_l] + nums[point_r] < nums[i] * -1)
                    point_l++;
                else if (nums[point_l] + nums[point_r] > nums[i] * -1)
                    point_r--;
                else{
                    result.push_back({nums[i], nums[point_l], nums[point_r]});
                    //指向下一个不同的数字
                    while ((point_l < point_r) && (nums[point_l] == result.back()[1]))
                        point_l++;
                    while ((point_l < point_r) && (nums[point_r] == result.back()[2]))
                        point_r--;
                }
            }
            //遇到相同的数字跳过
            while ((i + 1 < nums.size()) && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};