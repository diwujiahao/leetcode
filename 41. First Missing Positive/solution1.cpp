class Solution {
    set<int> data;
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i : nums){
            data.insert(i);
        }
        int index = 1;
        while(index){
            if (data.find(index) == data.end()){
                return index;
            }
            index++;
        }
        return 0;
    }
};