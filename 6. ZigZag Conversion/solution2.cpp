class Solution {
public:
    string convert(string s, int numRows) {
        //特殊情况判断
        if (numRows < 2)
            return s;
        //一般情况计算
        string result = "";
        for (int i = 0; i < numRows; i++){//i表示转换为N字型的行数
            int index = i;//index表示s的索引
            bool label = true;
            while(index < s.size()){
                //第一行和最后一行特殊
                if (i == 0 || i == numRows - 1){
                    result += s[index];
                    //更新索引index值
                    index += numRows * 2 - 2;
                }
                //其他行
                else{
                    result += s[index];
                    //更新索引index值
                    if (label){
                        index += (numRows - i - 1) * 2;
                    }
                    else{
                        index += i * 2;
                    }
                    //label翻转
                    label = !label;
                }
            }
        }
        return result;
    }
};