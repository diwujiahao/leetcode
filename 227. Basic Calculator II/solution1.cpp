class Solution {
    // + : -1
    // - : -2
    // * : -3
    // / : -4
    unordered_map<int, int> label_hash;
    
    
    stack<int> nums;
    stack<int> labels;
    int point = 0;
    
    
    int read(string s){
        // 数字
        if (s[point] >= '0' && s[point] <= '9'){
            int temp = 0;
            while (point < s.size() && s[point] >= '0' && s[point] <= '9'){
                temp = temp * 10 + (s[point++] - '0');
            }
            return temp;
        }
        // 运算符
        else{
            return label_hash[s[point++]];
        }
    }
    
    void caculate(int range){
        while (nums.size() >= 2 && labels.size() >= 1 && labels.top() <= range){
            int n1 = nums.top();
            nums.pop();
            int n2 = nums.top();
            nums.pop();
            char l = label_hash[labels.top()];
            labels.pop();
            if (l == '+'){
                nums.push(n2 + n1);
            }
            else if (l == '-'){
                nums.push(n2 - n1);
            }
            else if (l == '*'){
                nums.push(n2 * n1);
            }
            else if (l == '/'){
                nums.push(n2 / n1);
            }
            else{}
        }
    }
    
    
public:
    int calculate(string s) {
        label_hash[int('+')] = -1;
        label_hash[int('-')] = -2;
        label_hash[int('*')] = -3;
        label_hash[int('/')] = -4;
        label_hash[-1] = '+';
        label_hash[-2] = '-';
        label_hash[-3] = '*';
        label_hash[-4] = '/';
        
        while(point < s.size()){
            // 跳过空格
            while(s[point] == ' '){
                point++;
            }
            int temp;
            if (point < s.size()){
                temp = read(s);
            }
            else{
                break;
            }
            
            // 当前为运算符
            if (temp < 0){
                // + -
                if (temp == -1 || temp == -2){
                    caculate(-1);
                    labels.push(temp);
                }
                // * /
                else{
                    caculate(-3);
                    labels.push(temp);
                }
            }
            // 当前为数字
            else{
                nums.push(temp);
            }
        }
        caculate(-1);
        return nums.top();
    }
};