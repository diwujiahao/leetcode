class Solution {
    
    vector<int> find_count0(vector<int> in_count){
        vector<int> temp;
        for (int i = 0; i < in_count.size(); i++){
            if (in_count[i] == 0){
                temp.push_back(i);
            }
        }
        return temp;
    }
    
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in_count(numCourses, 0); // 每个节点的入度
        vector<vector<int>> graph(numCourses, vector<int>());
        
        for (auto p : prerequisites){
            graph[p.first].push_back(p.second);
            in_count[p.second]++;
        }
        
        while (1){
            // 获取当前入度为0的节点
            vector<int> temp = find_count0(in_count);
            // 没有入度为0的节点
            if (temp.size() == 0){
                break;
            }
            // 将所有入度为0的节点删除
            for (auto node : temp){
                in_count[node] = -1;
                for (auto neighbor : graph[node]){
                    in_count[neighbor]--;
                }
            }
        }
        
        for (int i = 0; i < in_count.size(); i++){
            if (in_count[i] > 0){
                return false;
            }
        }
        return true;
    }
};