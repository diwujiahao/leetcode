class Solution {
private:
    //前后括号转化函数
    char convert(char c){
        if (c == '(')
            return ')';
        else if (c == '[')
            return ']';
        else if (c == '{')
            return '}';
        else
            return ' ';
    }
public:
    bool isValid(string s) {
        stack<char> temp;//存储已经出现但未匹配的括号
        //遍历传入字符串
        for (char i : s){
            if (i == '{' || i == '(' || i == '[')//如果是前括号
                temp.push(i);//入栈
            else if (i == '}' || i == ')' || i == ']')//如果是后括号
                if (!temp.empty() && i == convert(temp.top()))//匹配成功
                    temp.pop();//出栈
                else//匹配失败
                    return false;
        }
        return temp.empty();
    }
};