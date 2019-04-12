class Solution {
    vector<int> data;
    // 存储数字
public:
    string convertToTitle(int n) {
        // 填充data
        while(n > 0){
            data.push_back((n-1) % 26);
            n = (n - 1) / 26;
        }
        // data数字转字母
        string result = "";
        for (int i = data.size() - 1; i >= 0; i--){
            result.push_back('A' + data[i]);
        }
        return result;
    }
};