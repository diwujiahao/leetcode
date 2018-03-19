class Solution {
private:
    //字符类型判断函数
    int judge(char n){
        if (n >= '0' && n <= '9')
            return 1;
        else if (n == '+' || n == '-')
            return 2;
        else
            return 0;
    }
public:
    int myAtoi(string str) {
        int point = 0;//指针变量
        long long result = 0;//结果变量
        int label = true;//正负标记
        //消除空格
        while(point < str.size() && str[point] == ' '){
            point++;
        }
        //录入正负号
        if (!judge(str[point])){
            return 0;
        }
        else if (str[point] == '+'){
            label = 1;
            point++;
        }
        else if (str[point] == '-'){
            label = -1;
            point++;
        }
        //转换数字
        while(point < str.size()){
            if (judge(str[point]) != 1)
                break;
            result = result * 10 + (str[point++] - '0') * label;
            //范围判断
            if (result > INT_MAX)
                return INT_MAX;
            else if (result < INT_MIN)
                return INT_MIN;
        }
        return int(result);
    }
};
