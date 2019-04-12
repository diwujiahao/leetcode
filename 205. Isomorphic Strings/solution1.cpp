// 构造正反哈希结构存储对应字符

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, char> hash;
        unordered_map<char, char> hash_r;
        for (int i = 0; i < s.size(); i++){
            if (hash.find(s[i]) == hash.end() && hash_r.find(t[i]) == hash_r.end()){
                hash[s[i]] = t[i];
                hash_r[t[i]] = s[i];
            }
            else if (hash.find(s[i]) != hash.end() && hash_r.find(t[i]) != hash_r.end()){
                if (hash[s[i]] != t[i] || hash_r[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};