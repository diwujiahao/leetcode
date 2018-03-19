class Solution {
private:
    unordered_map<char, int> hash;
public:
    Solution(){
        hash['I'] = 1;
        hash['X'] = 10;
        hash['C'] = 100;
        hash['M'] = 1000;
        hash['V'] = 5;
        hash['L'] = 50;
        hash['D'] = 500;
    }
    int romanToInt(string s) {
        int result = 0, temp = 0;//result:结果变量/temp:统计连续相同字母之和的临时变量
        //遍历所有字母
        for (int i = 0; i < s.size(); i++){
            temp = hash[s[i]];
            //将之后的相同字母一并统计存入temp
            while(s[i+1] && s[i+1] == s[i])
                temp += hash[s[i++]];
            //根据前后字母关系更新result
            if (hash[s[i]] > hash[s[i+1]])
                result += temp;
            else
                result -= temp;
        }
        //返回结果
        return result;
    }
};