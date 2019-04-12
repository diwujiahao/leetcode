class Solution {
    int binary_search(vector<int> numbers, int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            if (numbers[mid] > target){
                right = mid - 1;
            }
            else if (numbers[mid] < target){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++){
            int new_target = target - numbers[i];
            int index = binary_search(numbers, i+1, int(numbers.size()-1), new_target);
            if (index >= 0){
                return {i+1, index+1};
            }
        }
        return {};
    }
};