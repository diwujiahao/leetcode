// 时间复杂度过高，超时

class Solution {
    int recursion(int begin, int end){
        int count = 0;
        if (begin > end){
            return 1;
        }
        for (int i = begin; i <= end; i++){
            int left = recursion(begin, i-1);
            int right = recursion(i+1, end);
            count += left * right;
        }
        return count;
    }
public:
    int numTrees(int n) {
        return recursion(1, n);
    }
};