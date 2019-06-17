class Solution {
    vector<string> result;
    
    int left, right;
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // 特殊情况判断
        if (nums.size() == 0)
            return result;
        // 初始化左界为第一个元素
        left = nums[0];
        // 开始遍历所有数字
        for (int i : nums){
            // 第一次进入循环
            if (i == left){
                right = i;
                continue;
            }
            // 右界扩展一个
            if (i == right + 1){
                right += 1;
            }
            // 出现跳跃
            else{
                if (left == right)
                    result.push_back(to_string(left));
                else
                    result.push_back(to_string(left) + "->" + to_string(right));
                left = right = i;
            }
        }  
        if (left == right)
            result.push_back(to_string(left));
        else
            result.push_back(to_string(left) + "->" + to_string(right));
        
        return result;
    }
};