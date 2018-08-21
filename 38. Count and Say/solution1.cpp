class Solution {
private:
    // 字符串转换函数
    string process(string input){
        int count = 0;
        string output = "";
        for (int i = 0; i < input.size(); i++){
            count++;
            if (i == input.size()-1 || input[i] != input[i+1]){
                output += to_string(count) + input[i];
                count = 0;
            }
        }
        return output;
    }
public:
    string countAndSay(int n) {
        string temp = "1"; //初始化
        for (int i = 1; i < n; i++){
            temp = process(temp);
        }
        return temp;
    }
};
