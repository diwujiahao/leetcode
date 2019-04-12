class Solution {
public:
    string minWindow(string s, string t) {

        // map表示当前 begin~end 范围内的字母出现情况
        // map[i] 大于0，表示字母 i 仍然需要
        // map[i] 小于0，表示字母 i 多余出现次数的负数

        // counter 表示当前 begin~end 范围内缺少的字母总数

        vector<int> map(128, 0);
        for (auto i : t){
            map[i]++;
        }
        
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end]] > 0){
                counter--;
            }
            map[s[end]]--;
            end++;
            
            while (counter == 0){
                if (end - begin < d){
                    d = end - begin;
                    head = begin;
                }
                if (map[s[begin]] == 0){
                    counter++;
                }
                map[s[begin]]++;
                begin++;
            }
        }
        
        return (d == INT_MAX) ? "" : s.substr(head, d);
    }
};




// 另一种实现
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        vector<int> data(t.size(), 0);
        for (int i = 0; i < t.size(); i++){
            hash[t[i]] = i;
        }
        for (int i = 0; i < t.size(); i++){
            data[hash[t[i]]]--;
        }
        
        int left = 0, right = 0, count = t.size();
        int temp_begin = 0, temp_length = INT_MAX;
        while (right < s.size()){
            // 当前字母在t中有
            if (hash.find(s[right]) != hash.end()){
                if (data[hash[s[right]]] < 0){
                    count--;
                }
                data[hash[s[right]]]++;
                
                while (count == 0){
                    if (right - left + 1 < temp_length){
                        temp_begin = left;
                        temp_length = right - left + 1;
                    }
                    if (hash.find(s[left]) != hash.end()){
                        if (data[hash[s[left]]] == 0){
                            count++;
                        }
                        data[hash[s[left]]]--;
                    }
                    left++;
                }
            }
            
            right++;
        }
        return temp_length == INT_MAX ? "" : s.substr(temp_begin, temp_length);
    }
};