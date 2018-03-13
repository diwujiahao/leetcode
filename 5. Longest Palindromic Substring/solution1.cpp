class Solution {
private:
    bool judge(string s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int max_lenth = 0;
        string result = "";
        for (int i = 0; i <= s.size()-1; i++){
            for (int j = s.size(); j >= i+max_lenth; j--){
                if (judge(s.substr(i, j-i+1))){
                    if (j-i+1 > max_lenth){
                        max_lenth = j-i+1;
                        result = s.substr(i, j-i+1);
                    }
                    break;
                }
            }
        }
        return result;
    }
};