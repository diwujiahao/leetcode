class Solution {
    
    vector<int> seperate(string version){
        vector<int> nums;
        int begin = 0;
        while (begin < version.size()){
            int end = begin;
            while (end < version.size() && version[end] != '.'){
                end++;
            }
            nums.push_back(stoi(version.substr(begin, end - begin)));
            begin = end + 1;
        }
        return nums;
    }
    
    int judge(vector<int> nums1, vector<int> nums2){
        int point = 0;
        while(point < nums1.size() || point < nums2.size()){
            // nums1已经用完
            if (point >= nums1.size()){
                if (nums2[point] > 0){
                    return -1;
                }
            }
            // nums2已经用完
            else if (point >= nums2.size()){
                if (nums1[point] > 0){
                    return 1;
                }
            }
            // nums1 nums2 均为用完
            else{
                if (nums1[point] > nums2[point]){
                    return 1;
                }
                else if (nums1[point] < nums2[point]){
                    return -1;
                }
            }
            point++;
        }
        return 0;
    }
    
public:
    int compareVersion(string version1, string version2) {
        vector<int> nums1 = seperate(version1);
        vector<int> nums2 = seperate(version2);
        return judge(nums1, nums2);
    }
};