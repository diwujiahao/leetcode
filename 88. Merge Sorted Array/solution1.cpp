// 倒叙写入不用移动

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point_write = m + n - 1; // 写指针
        int point_read1 = m - 1, point_read2 = n - 1; // 读指针
        while (point_read1 >= 0 || point_read2 >= 0){
            // 若一个读指针遍历完成，将另一个读指针元素写入写指针位置
            if (point_read1 < 0){
                nums1[point_write--] = nums2[point_read2--];
            }
            else if (point_read2 < 0){
                nums1[point_write--] = nums1[point_read1--];
            }
            // 将两个读指针的较大元素写入写指针位置
            else if (nums1[point_read1] >= nums2[point_read2]){
                nums1[point_write--] = nums1[point_read1--];
            }
            else{
                nums1[point_write--] = nums2[point_read2--];
            }
        }
    }
};