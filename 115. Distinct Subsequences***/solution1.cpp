// dp[i]表示t的i前缀，在s的第n轮出现的次数

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp(t.size(), 0);
        for (char ss : s){
            for (int i = t.size()-1; i >= 0; i--){
                if (t[i] == ss){
                    dp[i] = ((i > 0) ? dp[i-1] : 1) + dp[i];
                }
            }
        }
        return dp.back();
    }
};



class Solution {
public:
	int numDistinct(string s, string t){
		vector<long long> dp(t.size() + 1, 0);
		dp[0] = 1;
		for (char ss : s){
			for (int i = t.size()-1; i >= 0; i--){
				if (t[i] == ss){
					dp[i+1] += dp[i];
				}
			} 
		}
		return dp.back();
	}
};