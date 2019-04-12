class Solution {
    unordered_map<string, vector<int>> hash;
    vector<vector<int>> data;
    int k;
    vector<int> result;
    
    // 检查一个vector中有几个大于0的数字
    // 检查当前位存储了几个单词
    int check(vector<int> temp){
        int count = 0;
        for (int i : temp){
            if (i >= 0){
                count++;
            }
        }
        return count;
    }
    
    // 从当前单词的候选位选择一个可用的（<0）或最小的
    int find_index(vector<int> v, string temp){
        vector<int> candidate = hash[temp];
        int min_index = INT_MAX, min_num = INT_MAX;
        for (int i : candidate){
            if (v[i] < 0){
                return i;
            }
            if (v[i] < min_num){
                min_num = v[i];
                min_index = i;
            }
        }
        return min_index;
    }

    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 特殊情况判断
        if (words.size() == 0 || s.size() == 0){
            return vector<int>();
        }
        // 初始化数据结构
        k = int(words[0].size()); // 单词长度
        data = vector<vector<int>>(s.size(), vector<int>(words.size(), -1));
        for (int i = 0; i < words.size(); i++){
            hash[words[i]].push_back(i);
        }
        // 动态规划
        for (int i = k - 1; i < s.size(); i++){
            if (i - k >= 0){
                data[i] = data[i-k];
            }
            string temp = s.substr(i - k + 1, k);
            // 当前位结束是一个单词
            if (hash.find(temp) != hash.end()){
                int index = find_index(data[i], temp);
                // 当前位为空--填入
                if (data[i][index] < 0){
                    data[i][index] = check(data[i]);
                }
                // 出现头位重复单词--填入后全部减一
                else if (data[i][index] == 0){
                    data[i][index] = check(data[i]);
                    // 去掉第一个单词
                    for (int j = 0; j < data[i].size(); j++){
                        if (data[i][j] >= 0){
                            data[i][j]--;
                        }
                    }
                }
                // 出现非头重复单词
                else{
                    data[i][index++] = check(data[i]);
                    // 去掉前index个单词
                    while (index--){
                        for (int j = 0; j < data[i].size(); j++){
                            if (data[i][j] >= 0){
                                data[i][j]--;
                            }
                        }
                    }
                }
            }
            // 当前位不是单词
            else{
                data[i] = vector<int>(words.size(), -1);
            }
            // 检查是否达到要求
            if (check(data[i]) == words.size()){
                result.push_back(i + 1 - k * int(words.size()));
            }
        }
        return result;
        
    }
};