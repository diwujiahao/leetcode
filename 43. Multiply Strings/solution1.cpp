class Solution {
private:
    vector<string> temp_result;// 中间结果 存储num1的每一位乘以num2的结果

    // 一位乘多位乘法运算
    string product(char num, string nums){
        if (num == "0")
            return "0";
        string output = ""; // 结果
        int carry = 0; // 进位
        // 相乘
        for (int i = int(nums.size()) - 1; i >= 0; i--){
            int temp = (num-'0') * (nums[i]-'0') + carry;
            carry = temp / 10;
            output = to_string(temp % 10) + output;
        }
        return carry ? to_string(carry) + output : output;
    }

    // 求和运算
    string add(vector<string> temp_result){
        int max_len = 0; // temp_result中字符串最大长度
        string output = ""; // 结果
        int carry = 0; // 进位
        // 统计max_len
        for (string i : temp_result)
            max_len = max(max_len, int(i.size()));
        // 求和
        for (int i = 0; i < max_len; i++){
            int temp = carry;
            for (string s : temp_result)
                if (i < s.size())
                    temp += (s[s.size()-i-1] - '0');
            carry = temp / 10;
            output = to_string(temp % 10) + output;
        }
        return carry ? to_string(carry) + output : output;
    }

public:
    string multiply(string num1, string num2) {
        int flag = int(num1.size()) - 1;
        for (char i : num1){
            string temp = product(i, num2);
            temp_result.push_back(temp + ((atoi(temp.c_str()) == 0) ? "" : string(flag,'0')));
            flag--;
        }
        return add(temp_result);
    }
};