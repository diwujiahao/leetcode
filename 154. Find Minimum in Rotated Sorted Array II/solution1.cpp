class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = int(nums.size()) - 1;
        while(begin < end){
            int mid = (begin + end) / 2;
            if (nums[mid] > nums[end]){
                begin = mid + 1;
                // begin可以越过最小值
            }
            else if(nums[mid] < nums[end]){
                end = mid;
                // 保证end不越过最小值
            }
            else{
                end--;
            }
        }
        return nums[begin];
    }
};