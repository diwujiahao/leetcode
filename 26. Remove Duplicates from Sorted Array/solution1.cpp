class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //特殊情况判断
        if (nums.size() < 1)
            return 0;
        //count:统计不同元素个数
        //temp:标记当前相同的元素
        //i:遍历数组的指针
        int count = 1, temp = nums[0];
        auto i = nums.begin() + 1;
        while(i < nums.end()){
            //遇到相同元素删除
            if (*i == temp){
                nums.erase(i--);
            }
            //遇到不相同元素修改count和temp
            else{
                temp = *i;
                count++;
            }
            i++;
        }
        return count;
    }
};