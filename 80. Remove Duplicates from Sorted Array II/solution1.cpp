class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int read = 1, write = 1; // 读写指针 
        int count = 1; // 临时统计变量
        while (read < nums.size()){
            // 与上一位相同
            if (nums[read] == nums[read-1]){
                // 已经重复超过了2个
                // 移动读指针
                if (count >= 2){
                    read++;
                    continue;
                }
                // 还没有重复超过两个
                // 写入并更新
                nums[write++] = nums[read++];
                count++;
            }
            // 与上一位不同
            else{
                // 写入并更新
                nums[write++] = nums[read++];
                count = 1;
            }
        }
        return (nums.size() == 0) ? 0 : write;
    }
};