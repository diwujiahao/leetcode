class Solution {
 
    // 计算两个线段相交的长度
    int compute(int line1_left, int line1_right, int line2_left, int line2_right){
        int left = max(line1_left, line2_left);
        int right = min(line1_right, line2_right);
        return right > left ? right - left : 0;
    }
    
    
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // 计算第一个长方形面积
        double S1 = (C - A) * (D - B);
        // 计算第二个长方形面积
        double S2 = (G - E) * (H - F);
        // 计算两个长方形相交的面积
        int width = compute(A, C, E, G);
        int height = compute(B, D, F, H);
        double S3 = width * height;
        return int(S1 + S2 - S3);
    }
};