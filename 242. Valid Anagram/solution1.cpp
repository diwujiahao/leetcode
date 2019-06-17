class Solution {
    
    // 将一个字符串统计字母频率
    unordered_map<char, int> build_hash(string s){
        unordered_map<char, int> hash_s;
        for (char i : s){       
            hash_s[i] = (hash_s.find(i)!=hash_s.end()) ? hash_s[i]+1 : 1;
        }
        return hash_s;
    }
      
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash_s = build_hash(s);
        unordered_map<char, int> hash_t = build_hash(t);
        // 检查字符数量是否相同
        if (hash_s.size() != hash_t.size()){
            return false;
        }
        // 检查字符出现次数是否相同
        for (auto i : hash_s){
            if (hash_t.find(i.first) == hash_t.end() || hash_t[i.first] != i.second){
                return false; 
            }
        }
        return true;
    }
};