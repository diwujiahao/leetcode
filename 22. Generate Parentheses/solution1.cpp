class Solution {
private:
    vector<string> result;//存储结果
    //递归函数
    //temp表示当前字符串
    //left表示"("可用个数
    //right表示当前")"可用个数
    void loop(string temp, int left, int right){
        if (left == 0 && right == 0){
            result.push_back(temp);
            return;
        }
        if (left > 0)
            loop(temp+"(", left-1, right+1);
        if (right > 0)
            loop(temp+")", left, right-1);
    }
public:
    vector<string> generateParenthesis(int n) {
        loop("", n, 0);
        return result;
    }
};