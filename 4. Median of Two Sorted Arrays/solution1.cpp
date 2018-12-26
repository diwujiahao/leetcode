class Solution {
    int len_nums1 = 0, len_nums2 = 0;
    int half_len = 0;
    double result = 0;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        len_nums1 = int(nums1.size());
        len_nums2 = int(nums2.size());
        half_len = (len_nums1 + len_nums2 + 1) / 2;
        
        //大小互换保证nums1长度大
        if (len_nums2 < len_nums1){
            swap(nums1, nums2);
            swap(len_nums1, len_nums2);
        }
        int i_min = 0, i_max = len_nums1;
        while (i_min <= i_max){
            //计算分割点 i j
            int i = (i_min + i_max) / 2;
            int j = half_len - i;
            //分割点错误1
            if (i < i_max && nums1[i] < nums2[j-1] )
                i_min++;
            //分割点错误2
            else if (i > i_min && nums1[i-1] > nums2[j])
                i_max--;
            //分割点正确
            else{
                int max_left = 0;
                //确定分割点左边最大值
                if (i == 0)
                    max_left = nums2[j-1];
                else if (j == 0)
                    max_left = nums1[i-1];
                else
                    max_left = max(nums1[i-1], nums2[j-1]);
                if ((len_nums1 + len_nums2) % 2 == 1)
                    return max_left;
                
                //确定分割点右边最小值
                int min_right = 0;
                if (i == len_nums1)
                    min_right = nums2[j];
                else if (j == len_nums2)
                    min_right = nums1[i];
                else
                    min_right = min(nums1[i], nums2[j]);
                return (max_left + min_right) / 2.0;
            }
        }
        
        return result;
    }
};