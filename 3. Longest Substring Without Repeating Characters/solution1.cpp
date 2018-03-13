class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int max_substring = 0;//结果变量
        int count = 0;//结尾处理计数变量
        for (int i = 0; i < s.size(); i++){
            //若第i个字母出现过
            if (hash.find(s[i]) != hash.end()){
                count = min(i - hash[s[i]], ++count);
                max_substring = max(max_substring, count);
                hash[s[i]] = i;
            }
            //若第i个字母还未出现过
            else{
                max_substring = max(max_substring, ++count);
                hash[s[i]] = i;
            }
        }
        return max_substring;
    }
};