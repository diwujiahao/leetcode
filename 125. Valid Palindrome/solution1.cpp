class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int left = 0, right = s.size() - 1;
        while (left < right){
            // 若left不是英文且不是数字，跳过
            if (!isalnum(s[left])){
                left++;
                continue;
            }
            // 若right不是英文且不是数字，跳过
            if (!isalnum(s[right])){
                right--;
                continue;
            }
            // 判断当前left，right是否相同
            if (s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};