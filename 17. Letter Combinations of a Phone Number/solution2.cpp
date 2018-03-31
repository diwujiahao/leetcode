class Solution {
private:
    //模拟手机按键的字母表
    vector<string> dic ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //待返回结果
    vector<string> result;
    //递归函数
    //temp: 当前生成的字符串
    //digits: 题目传入按键顺序
    //deep: 本轮递归遍历digits的下标数（按至第几个键）
    void next_one(string temp, string digits, int deep){
        for (char i : dic[digits[deep]-'0']){
            //所有输入都遍历过
            if (deep == digits.size() - 1)
                result.push_back(temp + i);//插入生成结果
            //仍没有完成遍历
            else
                next_one(temp+i, digits, deep+1);//继续遍历下一个输入
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string temp = "";
        next_one(temp, digits, 0);
        return result;
    }
};