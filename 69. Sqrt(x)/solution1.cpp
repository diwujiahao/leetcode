//二分查找

class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = x;
        while(left <= right){
            long mid = (left + right) / 2;
            //分情况处理
            if (mid * mid == x){
                return int(mid);
            }
            else if ((mid+1) * (mid+1) == x){
                return int(mid) + 1;
            }
            else if (mid * mid < x && (mid+1) * (mid+1) > x){
                return int(mid);
            }
            else if (mid * mid > x){
                right = mid - 1;
            }
            else if ((mid+1) * (mid+1) < x){
                left = mid + 1;
            }
            else{
                cout << "error!" << endl;
            }
        }
        return 0;
    }
};