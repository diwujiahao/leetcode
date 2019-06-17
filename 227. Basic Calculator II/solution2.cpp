class Solution {
    char label = '+';
    int temp_num = 0, result = 0;
    stack<int> nums;
    
public:
    int calculate(string s) {
        for (int i = 0; i < s.size(); i++){
            // 当前位为数字
            if (isdigit(s[i])){
                temp_num = temp_num * 10 + (s[i] - '0');
            }
            // 当前位为运算符||到最后一位
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == s.size() - 1){
                if (label == '+')
                    nums.push(temp_num);
                else if (label == '-')
                    nums.push(temp_num * -1);
                else{
                    if (label == '*')
                        temp_num = nums.top() * temp_num;
                    else
                        temp_num = nums.top() / temp_num;
                    nums.pop();
                    nums.push(temp_num);
                }

                temp_num = 0;
                label = s[i];
            }
        }
        
        while (!nums.empty()){
            result += nums.top();
            nums.pop();
        }
        return result;
        
    }
};