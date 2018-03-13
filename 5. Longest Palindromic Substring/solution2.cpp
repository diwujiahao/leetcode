class Solution {
private:
    string ss;
    vector<int> judge(int mid){
        int l = mid, r = mid;
        while (ss[r+1] && ss[r] == ss[r+1])
            r++;
        while (ss[l-1] && ss[r+1] && ss[l-1] == ss[r+1]){
            r++;
            l--;
        }
        return {l, r - l + 1};
    }
public:
    string longestPalindrome(string s) {
        ss = s;
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++){
            vector<int> temp = judge(i);
            if (temp[1] > len){
                len = temp[1];
                start = temp[0];
            }
        }
        return s.substr(start, len);
    }
};