class Solution {
    deque<int> temp;
    vector<int> data;
public:
    int titleToNumber(string s) {
        for (char i : s){
            temp.push_front(i - 'A' + 1);
        }
        data = vector<int>(temp.begin(), temp.end());
        int result = 0;
        for (int i = 0; i < data.size(); i++){
            result += data[i] * pow(26, i);
        }
        return result;
    }
};