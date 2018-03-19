class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;//结果变量
        //l、r分别表示左右指针
        //l、r中小的一个,以此为边界的最大容器已经确定,不用再留着
        for (int l = 0, r = int(height.size() - 1); l < r; ){
            //temp存储本轮的临时储水量
            int temp = (r - l) * (min(height[l], height[r]));
            //更新result
            result = max(result, temp);
            //移动指针
            if (height[l] < height[r])
                l++;
            else if (height[l] > height[r])
                r--;
            else{
                l++;
                r--;
            }
        }
        //返回结果
        return result;
    }
};
