class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_dis = INT_MAX;
        if (nums.size() < 3)
            return min_dis;
        //数组排序
        sort(nums.begin(), nums.end());
        //每次确定一个数 寻找另两个数
        for (int i = 0; i < nums.size(); i++){
            //声明指针寻找定和的两个数
            int point_l = i + 1, point_r = int(nums.size() - 1);
            while (point_l < point_r){
                int temp_dis = nums[point_l] + nums[point_r] + nums[i] - target;
                if (abs(temp_dis) < abs(min_dis))
                        min_dis = temp_dis;
                //进行判断
                if (temp_dis < 0){
                    //遇到相同的数字跳过
                    while (point_l < point_r && nums[point_l] == nums[point_l+1])
                        point_l++;
                    point_l++;
                }
                else if (temp_dis > 0) {
                    //遇到相同的数字跳过
                    while (point_l < point_r && nums[point_r] == nums[point_r-1])
                        point_r--;
                    point_r--;
                }
                else{
                    return target;
                }
            }
            //遇到相同的数字跳过
            while ((i + 1 < nums.size()) && nums[i] == nums[i+1])
                i++;
        }
        return min_dis + target;
    }
};