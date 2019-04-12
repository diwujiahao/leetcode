class Solution {

    // 合并 point_l 和 point_r
    // 默认 point_l 和 point_r 相邻
    void merge(vector<Interval> &intervals, vector<Interval>::iterator &point_l, vector<Interval>::iterator &point_r){
        if (point_l->end >= point_r->start){
            point_l->start = min(point_l->start, point_r->start);
            point_l->end = max(point_l->end, point_r->end);
            point_r = intervals.erase(point_r);
        }
        else{
            point_l++;
            point_r++;
        }
    }
    
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        // 将 newInterval 插入到合适位置
        for (int i = 0; i <= intervals.size(); i++){
            if (i == intervals.size()){
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
            else if (newInterval.start < intervals[i].start){
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        
        // 从左到右合并
        vector<Interval>::iterator point_l = intervals.begin(), point_r = intervals.begin() + 1;
        while(point_r != intervals.end()){
            merge(intervals, point_l, point_r);
        }
        
        return intervals;
    }
};