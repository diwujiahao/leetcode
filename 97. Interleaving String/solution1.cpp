class Solution {
    
    bool recursion(string s1, int point1, string s2, int point2, string s3, int point3){
        if (point3 >= s3.size()){
            return true;
        }
        
        if (s1[point1] == s3[point3] && s2[point2] == s3[point3]){
            return recursion(s1, point1+1, s2, point2, s3, point3+1) || recursion(s1, point1, s2, point2+1, s3, point3+1);
        }
        else if (s1[point1] == s3[point3]){
            return recursion(s1, point1+1, s2, point2, s3, point3+1);
        }
        else if (s2[point2] == s3[point3]){
            return recursion(s1, point1, s2, point2+1, s3, point3+1);
        }
        else{
            return false;
        }
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()){
            return false;
        }
        return recursion(s1, 0, s2, 0, s3, 0);
    }
};