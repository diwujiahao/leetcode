// 超时

class Solution {
    vector<pair<int, int>> result; // 存储结果
    
    // 临界点结构体
    struct critical{
        int loc;
        vector<int> buildings;
        critical(int l):loc(l){};
    };
    
    // 按照loc排序的辅助函数
    static bool mycmp(critical i,critical j) {
        return (i.loc < j.loc);
    }
    
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // 创建关键点列表
        vector<critical> critical_list;
        for (int i = 0; i < buildings.size(); i++){
            critical_list.push_back(critical(buildings[i][0]));
            critical_list.push_back(critical(buildings[i][1]));
        }
        // 关键点按照loc排序排序
        sort(critical_list.begin(), critical_list.end(), mycmp);
        // 填充关键点critical.buildings
        set<int> temp;
        int point = 0;
        for (int c_i = 0; c_i < critical_list.size(); c_i++){
            while (point < buildings.size() && critical_list[c_i].loc >= buildings[point][0]){
                temp.insert(point++);
            }
            for (auto i : temp){
                if (critical_list[c_i].loc < buildings[i][1]){
                    critical_list[c_i].buildings.push_back(i);
                }
                else{
                    temp.erase(point);
                }
            }
        }  
        // 生成结果
        for (auto c : critical_list){
            // 寻找当前关键点最高楼
            int temp_max = 0;
            for (int b : c.buildings){
                temp_max = max(temp_max, buildings[b][2]);
            }
            // 创建一个结果
            if (result.size() == 0 || temp_max != result.back().second){
                result.push_back(pair<int, int>(c.loc, temp_max));
            }
            
        }
        
        return result;
    }
};