class Solution {
public:
    void sortColors(vector<int>& nums) {
        //point_0永远指向第一个非0的地址
        //point_2永远指向倒叙第一个非2的地址
        //point为遍历指针
        int point_0 = 0, point_2 = int(nums.size()) - 1;
        int point = 0;
        //开始遍历
        while(point <= point_2){
            //point = 0
            if (nums[point] == 0){
                swap(nums[point], nums[point_0]);
                //更新指针
                point++;
                point_0++;
            }
            //point = 2
            else if (nums[point] == 2){
                swap(nums[point], nums[point_2]);
                //更新指针
                point_2--;
            }
            //point = 1
            else{
                point++;
            }
            
        }
    }
};
