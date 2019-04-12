class Solution {
    vector<pair<int, int>> result; //存储结果

    // 优先队列辅助函数
    struct Cmp{
        bool operator()(const vector<int> b1, const vector<int> b2){
            if (b1[2] == b2[2])
                return b1[1] > b2[1];
            return b1[2] < b2[2];
        }
    };
    
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // 创建关键点集合
        set<int> critical_set;
        for (int i = 0; i < buildings.size(); i++){
            critical_set.insert(buildings[i][0]);
            critical_set.insert(buildings[i][1]);
        }
        // 关键点集合转列表 并 排序
        vector<int> critical_list(critical_set.begin(), critical_set.end());
        sort(critical_list.begin(), critical_list.end());
        // 利用优先队列得到结果
        priority_queue<vector<int>, vector<vector<int>>, Cmp> data;
        int point = 0;
        for (auto i : critical_list){
            // 加入新的建筑
            while (point < buildings.size() && i >= buildings[point][0]){
                data.push(buildings[point++]);
            }
            // 走出之前的建筑
            while (data.size() > 0){
                if (i >= data.top()[1]){
                    data.pop();
                }
                else{
                    break;
                }
            }
            // 添加结果
            if (result.size() == 0){
                result.push_back(make_pair(i, data.top()[2]));
            }
            else if (data.size() == 0 && result.back().second != 0){
                result.push_back(make_pair(i, 0));
            }
            else if (data.top()[2] != result.back().second){
                result.push_back(make_pair(i, data.top()[2]));
            }
            
        }
        
        return result;
    }
};
