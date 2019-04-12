class Solution {
    bool check(int a, int b){
        string temp1 = to_string(a) + to_string(b);
        string temp2 = to_string(b) + to_string(a);
        
        for (int i = 0; i < temp1.size(); i++){
            if (temp1[i] > temp2[i]){
                return true;
            }
            else if (temp1[i] < temp2[i]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }

    // bool check2(int num1, int num2){
    //     string s1 = to_string(num1);
    //     string s2 = to_string(num2);
    //     string r1 = s1 + s2;
    //     string r2 = s2 + s1;
    //     return r1 >= r2;
    // }
public:
    string largestNumber(vector<int>& nums) {
        for (int i = int(nums.size()) - 1; i > 0; i--){
            for (int j = 0; j < i; j++){
                if (!check(nums[j], nums[j+1])){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        string result = "";
        for (int i : nums){
            result += to_string(i);
        }
        return (result[0] == '0') ? "0" : result;
    }
};