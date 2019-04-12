// 栈底永远存放一个标记，上次有效的开始位置，相当于一个右括号

class Solution {
    stack<int> data;
    int result = 0;
    int temp = 0;
public:
    int longestValidParentheses(string s) {
        data.push(-1);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                data.push(i);
            }
            else{
                data.pop();
                if (!data.empty()){
                    result = max(result, i - data.top());
                }
                else{
                    data.push(i);
                }
            }
        }
        return result;
    }
};