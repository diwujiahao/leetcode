// 构造正反哈希结构存储对应字符

class Solution {

    bool judge(string s, string t){
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, char> hash;
        for (int i = 0; i < s.size(); i++){
            if (hash.find(s[i]) == hash.end()){
                hash[s[i]] = t[i];
            }
            else{
                if (hash[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isIsomorphic(string s, string t) {
        return judge(s,t) && judge(t,s);
    }
};