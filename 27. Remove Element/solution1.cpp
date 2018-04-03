class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //point:遍历指针
        //count:新数组长度统计
        auto point = nums.begin();
        int count = 0;
        while (point < nums.end()){
            //遇到相同的元素删除
            if (*point == val){
                nums.erase(point--);
                count--;
            }
            point++;
            count++;
        }
        return count;
    }
};