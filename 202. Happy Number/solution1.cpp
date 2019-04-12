class Solution {
    
    int process(int n){
        int num = 0;
        while (n != 0){
            num += pow(n%10, 2);
            n /= 10;
        }
        return num;
    }
    
public:
    bool isHappy(int n) {
        unordered_map<int, int> hash;
        
        while(n != 1){
            if (hash.find(n) == hash.end()){
                hash[n] = 1;
            }
            else{
                return false;
            }
            n = process(n);
        }
        return true;
    }
};