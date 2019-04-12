class Solution {
    unordered_map<string, int> hash;
    vector<int> dist;
    vector<int> data;
    
    // 找到与word相差一个字母的单词列表
    vector<int> find_transformer(string word){
        vector<int> temp;
        for (int i = 0; i < word.size(); i++){
            int t = word[i];
            for (char c = 'a'; c <= 'z'; c++){
                if (c == t){
                    continue;
                }
                word[i] = c;
                if (hash.find(word) != hash.end()){
                    temp.push_back(hash[word]);
                }
            }
            word[i] = t;
        }
        return temp;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 构造初始化数据
        wordList.push_back(beginWord);
        dist = vector<int>(wordList.size(), 0);
        for (int i = 0; i < wordList.size(); i++){
            hash[wordList[i]] = i;
        }
        
        data.push_back(int(wordList.size())-1);
        // index 表示层次遍历的层数
        for (int index = 2; index < wordList.size(); index++){
            if (data.empty()){
                break;
            }
            vector<int> temp;
            for (int i : data){
                for (int j : find_transformer(wordList[i])){
                    
                    if (dist[j] == 0){
                        dist[j] = 1;
                        temp.push_back(j);
                        if (wordList[j] == endWord){
                            return index;
                        }
                    }
                }
            }
            data = temp;
        }
        
        return 0;
    }
};