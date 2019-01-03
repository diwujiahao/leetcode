class Solution {
    
public:
    string addBinary(string a, string b) {
        string result = "";
        int p_a = int(a.size()) - 1, p_b = int(b.size()) - 1;//指针
        int c = 0;//进位标记
        //相加
        while(p_a >= 0 && p_b >= 0){
            int temp = (a[p_a] - '0') + (b[p_b] - '0') + c;
            c = temp / 2;
            temp = temp % 2;
            result += temp + '0';
            p_a--;
            p_b--;
        }
        //高位补全
        while(p_a >= 0){
            int temp = (a[p_a] - '0') + c;
            c = temp / 2;
            temp = temp % 2;
            result += temp + '0';
            p_a--;
        }
        //高位补全
        while(p_b >= 0){
            int temp = (b[p_b] - '0') + c;
            c = temp / 2;
            temp = temp % 2;
            result += temp + '0';
            p_b--;
        }
        //进位补全
        if (c > 0){
            result += c + '0';
        }
        //转置
        reverse(result.begin(), result.end());
        return result;
    }
};