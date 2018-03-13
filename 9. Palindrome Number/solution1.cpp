//翻转一半的输入数字进行回文判断
class Solution {
public:
    bool isPalindrome(int x) {
        //x为原数字/revert为翻转数字
        int revert = 0;
        //特殊情况判断
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        //当x>revert时 将x的低位压入revert的低位后删除
        while(x > revert){
            revert = revert * 10 + (x % 10);
            x /= 10;
        }
        //对比后返回结果
        return (revert == x || revert / 10 == x);
    }
};