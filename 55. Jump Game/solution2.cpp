// 贪心
// pos 作为节点，倒叙遍历查看每步是否可以跳过 pos
// 如果跳过pos，则更新pos值
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = int(nums.size()) - 1;
        for (int i = int(nums.size() - 2); i >= 0; i--){
            if (i + nums[i] >= pos){
                pos = i;
            }
        }
        if (pos == 0){
            return true;
        }
        else{
            return false;
        }
    }
};
