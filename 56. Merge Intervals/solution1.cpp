/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    vector<Interval> result;
    //合并函数
    Interval combine(Interval a1, Interval a2){
        int min_num = 0, max_num = 0;
        if (a1.start > a2.start){
            swap(a1, a2);
        }
        min_num = a1.start;
        max_num = max(a1.end, a2.end);
        return Interval(min_num, max_num);
    }
    //排序辅助函数
    static bool sort_function(Interval a1, Interval a2){
        return a1.start < a2.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //特殊情况判断
        if (intervals.size() == 0){
            return result;
        }
        //按 start 排序
        sort(intervals.begin(), intervals.end(), sort_function);
        //循环merge
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            //i-1 和 i 没有交集
            if (intervals[i].start > result.back().end){
                result.push_back(intervals[i]);
            }
            else{
                result.back() = combine(result.back(), intervals[i]);
            }
        }
        return result;
    }
};
