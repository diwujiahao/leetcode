class Solution {
public:
    int strStr(string haystack, string needle) {
        //特殊情况判断
        if (needle.size() == 0)
            return 0;
        for (int i = 0; i < haystack.size(); i++){
            //若首字母一样 则继续匹配
            if (haystack[i] == needle[0]){
                bool label = true;//标记是否匹配成功
                for (int temp = i; temp < i + needle.size(); temp++){
                    if (haystack[temp] != needle[temp-i]){//匹配失败
                        label = false;
                        break;
                    }
                }
                if (label)
                    return i;
            }
        }
        return -1;
    }
};