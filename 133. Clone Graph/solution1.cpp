/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode* head = nullptr;
    
    UndirectedGraphNode* recursion(UndirectedGraphNode* node){
        // 拷贝当前节点
        UndirectedGraphNode* node_copy = new UndirectedGraphNode(node->label);
        hash[node] = node_copy;
        vector<UndirectedGraphNode*> temp_neighbors;
        // 递归制作邻居节点列表
        for (auto i : node->neighbors){
            // 当前邻居节点不存在
            if (hash.find(i) == hash.end()){
                temp_neighbors.push_back(recursion(i));
            }
            // 当前邻居节点已经存在了
            else{
                temp_neighbors.push_back(hash[i]);
            }
        }
        node_copy->neighbors = temp_neighbors;
        // 返回值
        return node_copy;
    }
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node){
            return head;
        }
        head = recursion(node);
        return head;
    }
};
