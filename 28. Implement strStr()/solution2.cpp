// kmp算法
// https://blog.csdn.net/v_july_v/article/details/7041827
// 《编程之法：面试和算法心得》第4.4节中。
class Solution {
    //构造next数组
    vector<int> create_next(string needle){
        vector<int> next(int(needle.size()), 0);
        next[0] = -1;
        int k = -1, j = 0;
        while (j < needle.size() - 1){
            if (k == -1 || needle[j] == needle[k])
                next[++j] = ++k;//匹配成功/写入next
            else
                k = next[k];//匹配失败/根据next回溯
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        //构造next数组
        vector<int> next = create_next(needle);
        //开始匹配
        int i = 0, j = 0;
        while ((i < int(haystack.size())) && (j < int(needle.size()))){
            if (j == -1 || haystack[i] == needle[j]){
                i++;j++;
            }
            else{
                j = next[j];//匹配失败/根据next回溯
            }
        }
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }
};