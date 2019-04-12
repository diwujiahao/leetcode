class Solution {
    string first = "";
    bool label_e = false;
    string second = "";
    // 去除字符串尾的空格
    string strip_space(string s){
        string temp = "";
        int point_l = 0, point_r = int(s.size()) - 1;
        while (s[point_l] == ' '){
            point_l++;
        }
        while (s[point_r] == ' '){
            point_r--;
        }
        for (int i = point_l; i <= point_r; i++){
            temp += s[i];
        }
        return temp;
    }
    // 按照第一个e分成前后两部分
    bool seg(string s){
        bool label = false;
        for (char i : s){
            if (i == 'e' && !label){
                label = true;
                label_e = true;
            }
            else if (i == 'e' && label){
                return false;
            }
            else if (label){
                second += i;
            }
            else{
                first += i;
            }
        }
        return true;
    }
    // 检查前半部分格式
    bool check_first(){
        int point = 0;
        bool label_point = false;// 小数点标记
        int label_sign = 0;// 正负号标记
        // 处理首位正负号
        if (first.size() > 0 && (first[0] == '+' || first[0] == '-')){
            point++;
            label_sign = 1;
        }
        // 判断长度是否出错
        if (first.size() - label_sign == 0){
            return false;
        }
        // 检查数字部分
        while (point < first.size()){
            if (first[point] == '.'){
                if (! label_point){
                    label_point = true;
                    if (first.size() - label_sign == 1){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if (first[point] >= '0' && first[point] <= '9'){}
            else{
                return false;
            }
            point++;
        }
        return true;
    }
    // 检查后半部分格式
    bool check_second(){
        int point = 0;
        int label_sign = 0;// 正负号标记
        // 处理首位正负号
        if (second.size() > 0 && (second[0] == '+' || second[0] == '-')){
            point++;
            label_sign = 1;
        }
        // 判断长度是否出错
        if (label_e && (second.size() - label_sign == 0)){
            return false;
        }
        // 检查数字部分
        while (point < second.size()){
            if (second[point] >= '0' && second[point] <= '9'){}
            else{
                return false;
            }
            point++;
        }
        return true;
    }
    
public:
    bool isNumber(string s) {
        // 去除空格
        s = strip_space(s);
        // 分割字符串（分界点为e）
        if (!seg(s)){
            return false;
        }
        // 检查前半部分格式
        if (!check_first()){
            return false;
        }
        // 检查后半部分格式
        if (!check_second()){
            return false;
        }
        return true;
    }
};
