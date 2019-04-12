// 拓扑搜索

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in_count(numCourses, 0); // 每个节点的入度
        vector<vector<int>> graph(numCourses, vector<int>()); // 记录每个节点指向的节点
        queue<int> temp; // 记录当前出度为0的节点
        vector<int> result;
        
        for (auto p : prerequisites){
            graph[p.second].push_back(p.first);
            in_count[p.first]++;
        }
        
        // 获取当前出度为0的节点
        for (int i = 0; i < in_count.size(); i++){
            if (in_count[i] == 0){
                temp.push(i);
            }
        }
        // 每次出栈一个出度为0的节点
        while (!temp.empty()){
            int node = temp.front();
            result.push_back(node);
            temp.pop();
            in_count[node]--;
            for (auto i : graph[node]){
                if (--in_count[i] == 0){
                    temp.push(i);
                }
            }
        }
        // 根据其余节点的出度判断是否遍历完全
        for (int i = 0; i < in_count.size(); i++){
            if (in_count[i] > 0){
                return vector<int>();
            }
        }
        return result;;
    }
};