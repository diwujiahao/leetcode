class Solution {
    vector<string> result; // 存储结果
    string input_s; // 输入
    
    // 检查IP一小段合理性
    bool valid(string segment){
        // 长度合理
        if (segment.size() > 3 || segment.size() == 0){
            return false;
        }
        // 范围合理
        if (stoi(segment) > 255){
            return false;
        }
        // 首位不能出现0，除了0本身
        if (segment[0] == '0' && segment.size() != 1){
            return false;
        }
        return true;
    }
    
    void DFS(vector<string> temp, int point){
        // temp中存有4个合法IP段 && 遍历完全，添加一个结果并返回
        if (temp.size() == 4 && point == input_s.size()){
            result.push_back(temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3]);
            return;
        }
        // 有多余数字，返回
        else if (temp.size() == 4){
            return;
        }
        // DFS
        for (int i = 0; i < 3 && point + i < input_s.size(); i++){
            string test = input_s.substr(point, i + 1);
            if (valid(test)){
                temp.push_back(test);
                DFS(temp, point + i + 1);
                temp.pop_back();
            }
        }
    }
    
    
public:
    vector<string> restoreIpAddresses(string s) {
        input_s = s;
        vector<string> temp;
        DFS(temp, 0);
        return result;
    }
};
