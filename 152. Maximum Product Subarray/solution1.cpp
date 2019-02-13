class Solution {

    // 假设begin和end间没有0
    // 返回最大子串乘积
    int maxProductWithout0(vector<int> nums, int begin, int end){
        int count = 0; // 负数个数统计
        int product = 1; // 所有数字乘积
        // 统计 count 和 product
        for (auto i = begin; i <= end; i++){
            if (nums[i] < 0){
                count++;
            }
            product *= nums[i];
        }
        // 负数有偶数个--返回product
        if (count % 2 == 0){
            return product;
        }
        // 负数有奇数个--拿掉第一个或最后一个负数比大小
        else{
            // 正
            int product1 = product;
            int index = begin;
            while(nums[index] > 0){
                product1 /= nums[index++];
            }
            if (index < end){
                product1 /= nums[index];
            }
            // 反
            int product2 = product;
            index = end;
            while(nums[index] > 0){
                product2 /= nums[index--];
            }
            if (index > begin){
                product2 /= nums[index];
            }
            return max(product1, product2);
        }
    }
public:
    int maxProduct(vector<int>& nums) {
        vector<int> result; // 备选答案
        bool zero = false; // 标记是否出现0

        // 用0将所有子串分开，分别调用子函数 maxProductWithout0
        int begin = 0;
        while(begin < nums.size() && nums[begin] == 0){
            begin++;
            zero = true;
        }
        while(begin < nums.size()){
            int end = begin;
            while(end + 1 < nums.size() && nums[end + 1] != 0){
                end++;
                zero = true;
            }
            result.push_back(maxProductWithout0(nums, begin, end));
            begin = end + 1;
            while(begin < nums.size() && nums[begin] == 0){
                begin++;
                zero = true;
            }
        }
        if (zero){
            result.push_back(0);
        }
        return (result.size() > 0) ? *max_element(result.begin(), result.end()) : 0;
    }
};