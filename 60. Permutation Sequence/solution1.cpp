class Solution {
    int k_index = 0;
    string result = "";
    void get(string standard_string, string temp, int k){
        //到达叶子节点
        if (standard_string.size() == 0){
            k_index ++;
            if (k_index == k){
                result = temp;
            }
            return;
        }
        //回溯
        for (int i = 0; i < standard_string.size(); i++){
            char c = standard_string[i];
            temp += c;
            standard_string.erase(i, 1);
            get(standard_string, temp, k);
            standard_string.insert(standard_string.begin() + i, c);
            temp.erase(temp.size()-1, 1);
            if (result.size() > 0){
                return;
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        string standard_string = "";
        for (int i = 1; i <= n; i++){
            standard_string += char(i+'0');
        }
        string temp = "";
        get(standard_string, temp, k);
        return result;
    }
};