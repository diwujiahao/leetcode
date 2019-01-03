class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0){
            return {1};
        }
        //加一
        int point = int(digits.size()) - 1;
        digits[point] += 1;
        //进位操作
        while(digits[point] > 9){
            digits[point] -= 10;
            //不需要添加位数
            if (point - 1 >= 0){
                digits[point-1] += 1;
            }
            //需要加一位
            else{
                digits.insert(digits.begin(), 1);
            }
            point -= 1;
        }
        return digits;
    }
};