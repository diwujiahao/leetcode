// 二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = int(nums.size()) - 1;
        while(begin < end){
            int mid = (begin + end) / 2;
            if (nums[mid] > nums[nums.size()-1]){
                begin = mid + 1;
                // begin可以越过最小值
            }
            else if(nums[mid] < nums[nums.size()-1]){
                end = mid;
                // 保证end不越过最小值
            }
            else{
                // 由于没有重复元素
                // 所以不可能出现本情况
            }
        }
        return nums[begin];
    }
};