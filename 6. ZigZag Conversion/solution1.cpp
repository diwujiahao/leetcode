class Solution {
public:
    string convert(string s, int numRows) {
        //特殊情况判断
        if (numRows < 2)
            return s;
        //统计Z字型数据到result结构中
        vector<string> data(numRows, "");
        int row = 0, step = 1;
        for (int i = 0; i < s.size(); i++){
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            data[row] += s[i];
            row += step;
        }
        //将Z字型数据整合为字符串
        string result = "";
        for (int i = 0; i < numRows; i++){
            result += data[i];
        }
        return result;
    }
};