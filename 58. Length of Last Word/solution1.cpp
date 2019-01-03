class Solution {
public:
    int lengthOfLastWord(string s) {
        //去除末尾空格
        int begin_p = int(s.size()) - 1;
        while(begin_p >= 0 && s[begin_p] == ' '){
            begin_p--;
        }
        //开始统计最后一个单词长度
        int count = 0;
        for(int i = begin_p; i >=0; i--){
            if (s[i] != ' '){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};
