class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //统计变量 / 写指针
        int count = 0;
        //循环 / i为读指针
        for (int i = 0; i < nums.size(); i++)
        	//遇到不一样的元素就写入写指针位置
            if (nums[i] != val)
                nums[count++] = nums[i];
        return count;
    }
};