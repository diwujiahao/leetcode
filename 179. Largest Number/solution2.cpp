class Solution {
    
public:
    static bool check(string &s1, string &s2){
        string r1 = s1 + s2;
        string r2 = s2 + s1;
        return r1 > r2;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for (int i : nums){
            temp.push_back(to_string(i));
        }
        sort(temp.begin(), temp.end(), check);
        string result = "";
        for (string i : temp){
            result += i;
        }
        return (result[0] == '0') ? "0" : result;
    }
};