// 找到最大元素位置后，分别处理左右两边
// result 每次 + （路过的最大元素 - 当前元素 = 储水量）

class Solution {
    int result = 0;
    int most_height = 0, most_height_index = -1;
    int temp_wall;
public:
    int trap(vector<int>& height) {
        // 找到最大元素
        for (int i = 0; i < height.size(); i++){
            if (most_height < height[i]){
                most_height = height[i];
                most_height_index = i;
            }
        }
        // 处理左半边
        temp_wall = 0;
        for (int i = 0; i < most_height_index; i++){
            result += max(0, temp_wall - height[i]);
            temp_wall = max(temp_wall, height[i]);
        }
        // 处理右半边
        temp_wall = 0;
        for (int i = height.size()-1; i > most_height_index; i--){
            result += max(0, temp_wall - height[i]);
            temp_wall = max(temp_wall, height[i]);
        }
        return result;
    }
};