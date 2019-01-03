class Solution {
public:
    void sortColors(vector<int>& nums) {
        //point_0永远指向第一个非0的地址
        //point_2永远指向倒叙第一个非2的地址
        //point为遍历指针
        int point_0 = 0, point_2 = int(nums.size()) - 1;
        int point = 0;
        //初始化三个指针
        while (point_0 < nums.size() && nums[point_0] == 0){
            point_0++;
        }
        while (point_2 >= 0 && nums[point_2] == 2){
            point_2--;
        }
        point = point_0;
        //开始遍历
        while(point <= point_2){
            //point = 0
            if (nums[point] == 0){
                swap(nums[point], nums[point_0]);
                //更新指针
                while (point_0 < nums.size() && nums[point_0] == 0){
                    point_0++;
                }
                while (point_2 >= 0 && nums[point_2] == 2){
                    point_2--;
                }
                point = max(point_0, point);
            }
            //point = 2
            else if (nums[point] == 2){
                swap(nums[point], nums[point_2]);
                //更新指针
                while (point_0 < nums.size() && nums[point_0] == 0){
                    point_0++;
                }
                while (point_2 >= 0 && nums[point_2] == 2){
                    point_2--;
                }
                point = max(point_0, point);
            }
            //point = 1
            else{
                point++;
            }
            
        }
    }
};