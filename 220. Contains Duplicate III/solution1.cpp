// 利用集合的红黑树查找功能--实现候选数字的快速确定


class Solution {
    // |x - nums[i]| <= t    ==>   -t <= x - nums[i] <= t;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<double> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); i++) {
            // 保证集合窗口大小
            if (i > k)
                window.erase(double(nums[i-k-1])); // keep the set contains nums i j at most k
            
            // 保证 x-nums[i] >= -t ==> x >= nums[i]-t 限制
            auto pos_left = window.lower_bound(double(nums[i]) - double(t));
            // 保证 x - nums[i] <= t ==> x <= nums[i]+t 限制
            if (pos_left != window.end() && *pos_left <= double(nums[i]) + double(t))
                return true;
            // 保证集合窗口大小
            window.insert(double(nums[i]));
        }
        return false;
    }
};