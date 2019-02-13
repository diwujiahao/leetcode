class Solution {
    void reverse(string &s, int begin, int end){
        while(begin < end){
            swap(s[begin++], s[end--]);
        }
    }
    void process_space(string &s){
        int index = 0;
        while(s[index] == ' '){
            s.erase(index, index+1);
        }
        index = int(s.length()) - 1;
        while (s[index] == ' '){
            s.erase(index, index+1);
            index--;
        }
        index = 0;
        while(index < s.length()){
            if (s[index] == ' '){
                while(s[index+1] == ' '){
                    s.erase(index+1, 1);
                }
            }
            index++;
        }
    }
public:
    void reverseWords(string &s) {
        // 删除所有多余的空格
        process_space(s);
        // 整体翻转
        reverse(s, 0, int(s.length()) - 1);
        // 局部翻转
        int begin = 0;
        while(begin < s.length()){
            if (s[begin] == ' '){
                begin++;
                continue;
            }
            int end = begin;
            while (end + 1 < s.length() && s[end + 1] != ' '){
                end++;
            }
            reverse(s, begin, end);
            begin = end + 1;
        }  
    }
};