 /*
    思路：摩尔投票升级版，超过n/3的数最多只能有两个；
    先选出两个候选人A,B,遍历数组，如果投A（等于A），则A的票数++;如果投B，B的票数++；
    如果A,B都不投（即与A，B都不相等）,那么检查此时是否AB中候选人的票数是否为0，如果为0,则成为新的候选人；
    如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均--；
    遍历结束后选出两个候选人，但是这两个候选人是否满足>n/3，还需要再遍历一遍数组，找出两个候选人的具体票数
     */

class Solution {
    vector<vector<int>> candidate = {{-1,0},{-1,0}};
    vector<int> result;
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 特殊情况判断
        if (nums.size() == 0)
            return result;
        // 初始化两个候选人
        vector<vector<int>> candidate = {{nums[0],0},{nums[0],0}};
        // 通过投片机制，筛选两个候选人
        for (int i : nums){
            if (i == candidate[0][0]){
                candidate[0][1]++;
                continue;
            }
            if (i == candidate[1][0]){
                candidate[1][1]++;
                continue;
            }
            if (candidate[0][1] == 0){
                candidate[0] = {i,1};
                continue;
            }
            if (candidate[1][1] == 0){
                candidate[1] = {i,1};
                continue;
            }
            //此时两个候选人的票数都大于1，且当前选名不投AB，那么A,B对应的票数都要--;
            candidate[0][1]--;
            candidate[1][1]--;
        }
        // 检验两个候选人是否合格
        candidate[0][1] = 0;
        candidate[1][1] = 0;
        for (int i : nums){
            if (i == candidate[0][0]){
                candidate[0][1]++;
            }
            else if (i == candidate[1][0]){
                candidate[1][1]++;
            }
        }
        // 输出合格候选人
        if (candidate[0][1] > nums.size()/3){
            result.push_back(candidate[0][0]);
        }
        if (candidate[1][1] > nums.size()/3){
            result.push_back(candidate[1][0]);
        }
        
        return result;
        
    }
};