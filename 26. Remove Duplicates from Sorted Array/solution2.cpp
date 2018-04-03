class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //write_point:写指针
        //read_point:读指针
        int write_point = 0, read_point = 0;
        //循环
        while (read_point < nums.size()){
            //将读指针的值写入写指针位置
            nums[write_point++] = nums[read_point++];
            //将读指针移动到下一个待写入的位置(下一个值不一样的位置)
            while(nums[read_point] == nums[read_point-1])
                read_point++;
        }
        return write_point;
    }
};