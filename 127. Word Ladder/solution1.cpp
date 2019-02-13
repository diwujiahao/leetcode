class Solution {
    // 存储每个单词的可转换单词
    unordered_map<string, vector<int>> map;
    // 存储单词的访问情况（第i层访问）
    unordered_map<string, int> visited;
    // 辅助实现BFS的队列
    queue<string> data;
    
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
        data.push(beginWord);
        visited[beginWord] = 1;
        while (!data.empty()){
            // 取出一个单词
            string temp = data.front();
            data.pop();
            // 查看是否结束
            if (temp == endWord){
                return visited[temp];
            }
            // 将当前单词的转换单词放入队列中
            for (int i : map[temp]){
                if (visited[wordList[i]] == 0){
                    visited[wordList[i]] = visited[temp] + 1;
                    data.push(wordList[i]);
                }
            }
        }
        return 0;
    }
};
