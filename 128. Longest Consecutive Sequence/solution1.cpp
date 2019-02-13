class Solution {
    set<int> data;
    int result = 0;
    void find_Consecutive(int temp){
        int count = 1;
        int point = temp - 1;
        while (data.find(point) != data.end()){
            count++;
            data.erase(point--);
        }
        point = temp + 1;
        while (data.find(point) != data.end()){
            count++;
            data.erase(point++);
        }
        result = max(result, count);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        data = set<int>(nums.begin(), nums.end());
        for (int temp : nums){
            // 若数字不在集合内，则已经被使用过
            if (data.find(temp) == data.end()){
                continue;
            }
            // 若数字在集合内，寻找连续的数字
            find_Consecutive(temp);
        }
        return result;
    }
};