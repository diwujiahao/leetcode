class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 获取所有数字的异或结果 temp
        int temp = 0;
        for (int i : nums){
            temp ^= i;
        }
        // 获取temp中为1的位数，并以此位作为区分方式（divide）
        int divide = 0;
        while(1){
            if (temp & int(pow(2, divide))){
                break;
            }
            divide++;
        }
        divide = pow(2, divide);
        // 分开异或，获得结果
        int temp1 = 0, temp2 = 0;
        for (int i : nums){
            if (i & divide){
                temp1 ^= i;
            }
            else{
                temp2 ^= i;
            }
        }
        return vector<int>{temp1, temp2};
    }
};