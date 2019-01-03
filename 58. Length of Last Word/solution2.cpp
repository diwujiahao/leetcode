class Solution {
public:
    int lengthOfLastWord(string s) {
        //去除末尾空格
        while(int(s.size()) > 0 && s[int(s.size()) - 1] == ' '){
            s.erase(s.size() - 1);
        }
        //开始统计最后一个单词长度
        int count = 0;
        for(int i = int(s.size()) - 1; i >=0; i--){
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
