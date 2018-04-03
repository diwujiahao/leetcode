class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //特殊情况判断
        if (nums.size() == 0)
            return;
        //寻找倒序最后一个降序数字
        int point = int(nums.size()) - 1;//指针
        while (point > 0 && nums[point - 1] >= nums[point])
            point--;
        //所有数字均为降序
        if (point == 0)
            sort(nums.begin(), nums.end());
        //最后一个数字比倒数第二个小
        else if (point == nums.size() - 1)
            swap(nums[point], nums[point-1]);
        //其他情况/此时point指向倒序最后一个降序数字
        else{
            int temp_point = point - 1, flag_point = -1, flag = INT_MAX;
            //查找point及其后大于point-1的最小数字
            while(point < nums.size()){
                if (nums[point] > nums[temp_point] && nums[point] < flag){
                    flag = nums[point];
                    flag_point = point;
                }
                point++;
            }
            //将找到的数字与point-1=temp_point互换
            swap(nums[flag_point], nums[temp_point]);
            //升序排列temp_point后的数组
            sort(nums.begin()+temp_point+1, nums.end());
        }
    }
};