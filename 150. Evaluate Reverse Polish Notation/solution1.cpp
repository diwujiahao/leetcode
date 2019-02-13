class Solution {
    stack<int> data;
public:
    int evalRPN(vector<string>& tokens) {
        for (string i : tokens){
            if (i == "+"){
                double num1, num2;
                num2 = data.top();
                data.pop();
                num1 = data.top();
                data.pop();
                data.push(num1 + num2);
            }
            else if (i == "-"){
                double num1, num2;
                num2 = data.top();
                data.pop();
                num1 = data.top();
                data.pop();
                data.push(num1 - num2);
            }
            else if (i == "*"){
                double num1, num2;
                num2 = data.top();
                data.pop();
                num1 = data.top();
                data.pop();
                data.push(num1 * num2);
            }
            else if (i == "/"){
                double num1, num2;
                num2 = data.top();
                data.pop();
                num1 = data.top();
                data.pop();
                data.push(num1 / num2);
            }
            else{
                data.push(stoi(i));
            }
        }
        return data.top();
    }
};
