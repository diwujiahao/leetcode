class Solution {
    vector<vector<string>> result;
    int result_index = 0;
    map<string, int> hash;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 遍历输入list
        for (int i = 0; i < strs.size(); i++){
            //生成key
            string key = strs[i];
            sort(key.begin(), key.end());
            //已经存在的key
            if (hash.find(key) != hash.end()){
                int index = hash[key];
                result[index].push_back(strs[i]);
            }
            //key不存在
            else{
                hash[key] = result_index++;
                vector<string> temp = {strs[i]};
                result.push_back(temp);
            }
        }
        return result;
    }
};
