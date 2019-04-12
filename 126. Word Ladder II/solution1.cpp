class Solution {
    // 存储一个单词的 transform 单词
    unordered_map<string, vector<int>> map;
    // 记录访问情况
    unordered_map<string, int> visited;
    // bfs 辅助数据结构
    queue<vector<string>> data;
    // 最短达到距离
    int min_len = INT_MAX;
    // 结果
    vector<vector<string>> result;
    
    // 判断两个字符串是不是转化单词（只有一位不同）
    bool is_transform(string str1, string str2){
        int count = 0;
        for (int i = 0; i < str1.size(); i++){
            if (str1[i] != str2[i]){
                count++;
            }
        }
        return count == 1;
    }

    
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 构造初始化数据
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++){
            visited[wordList[i]] = 0;
            map[wordList[i]] = vector<int>();
            for (int j = 0; j < wordList.size(); j++){
                if (is_transform(wordList[i], wordList[j])){
                    map[wordList[i]].push_back(j);
                }
            }
        }
        // BFS
        data.push(vector<string>(1, beginWord));
        visited[beginWord] = 1;
        while (!data.empty()){
            // 取出一个队首
            vector<string> temp = data.front();
            data.pop();
            
            if (temp.size() > min_len){
                break;
            }
            if (temp.back() == endWord){
                min_len = temp.size();
                result.push_back(temp);
            }
            for (int i : map[temp.back()]){
                if (visited[wordList[i]] == 0 || visited[wordList[i]] > temp.size()){
                    visited[wordList[i]] = visited[temp.back()] + 1;
                    temp.push_back(wordList[i]);
                    data.push(temp);
                    temp.pop_back();
                }
            }
        }
        
        return result;
    }
};