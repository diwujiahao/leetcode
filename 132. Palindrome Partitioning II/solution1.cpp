// 超时
// 使用131. Palindrome Partitioning方法迁移
// 实际统计次数不需要遍历

class Solution {
    int result = INT_MAX;
    
    bool check(string s, int left, int right){
        while (left < right){
            if (s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
    
    void recursion(string s, int index, vector<string> temp){
        // 遍历完毕，添加一个结果
        if (index >= s.size()){
            result = min(result, int(temp.size()) - 1);
        }
        // 
        for (int i = index; i < s.size(); i++){
            if (check(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                recursion(s, i+1, temp);
                temp.pop_back();
            }  
        }
    }
    
public:
    int minCut(string s) {
        recursion(s, 0, vector<string>());
        return result;
    }
};