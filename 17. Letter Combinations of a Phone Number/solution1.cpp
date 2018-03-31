class Solution {
private:
    vector<string> dic = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<int> count = {0,0,3,3,3,3,3,4,3,4};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0)
            return result;
        //统计一共有多少字符串
        int num_count = 1;
        for (int i = 0; i < digits.size(); i++)
            num_count *= count[digits[i]-'0'];
        //取出待组合的数组dic_/数组内元素个数count_
        vector<string> dic_;
        vector<int> count_;
        for (int i = 0; i < digits.size(); i++){
            dic_.push_back(dic[digits[i]-'0']);
            count_.push_back(count[digits[i]-'0']);
        }
        //赋值count_到point作为指针
        vector<int> point(count_.size(), 0);
        //开始组合
        while(num_count > 0){
            string temp = "";//临时变量负责存储一个待返回字符串
            for (int i = 0; i < dic_.size(); i++)
                temp += dic_[i][point[i]];
            result.push_back(temp);//将temp插入result
            //更新point指针
            int label = int(point.size()) - 1;
            point[label]++;
            while(point[label] == count_[label]){
                point[label] = 0;
                if (label > 0){
                    label--;
                    point[label]++;
                }
            }
            num_count--;
        }
        return result;
    }
};