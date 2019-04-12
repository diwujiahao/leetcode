class Solution {
    unordered_map<string, int> data;
    vector<string> result;
    
    bool push_data(string s, int i){
        // i之前不足10位的输入，放弃
        if (i < 9){
            return false;
        }

        string hashNum = s.substr(i - 9, 10);
        if (data.find(hashNum) != data.end()){
            // 第一次出现重复
            if (data[hashNum] == 1){
                data[hashNum]++;
                return true;
            }
            else{
                // 已经加入结果result中
                return false;
            }
            
        }
        // 存储
        data[hashNum] = 1;
        return false;
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        for (int i = 0; i < s.size(); i++){
            if (push_data(s, i)){
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};