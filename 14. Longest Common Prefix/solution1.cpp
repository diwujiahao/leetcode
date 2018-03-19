class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //特殊情况判断
        if (strs.size() == 0)
            return "";
        //一般情况计算
        string result = "";
        //n表示每个字符串的第n个字母
        for (int n = 0; n < strs[0].size() ; n++){
            char temp = strs[0][n];
            //i表示第i个字符串
            for (int i = 1; i < strs.size(); i++){
                //若第n个字母不再为公共前缀 返回
                if (strs[i][n] != temp)
                    return result;
            }
            //若第n个字母仍为公共前缀 加入第n个字母
            result += temp;
        }
        return result;
    }
};