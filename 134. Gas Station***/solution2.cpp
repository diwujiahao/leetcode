class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // result: 出发节点
        // sum: 剩余油量统计
        int result = 0, sum = 0;
        for (int i = 0; i < gas.size(); i++){
            // 做减法，将加油站油量与耗费油量统一
            gas[i] = gas[i] - cost[i];
            // 更新现有油量
            sum += gas[i];
            // 如果出现走不过去的情况，重新从下一节点开始
            if (sum < 0){
                sum = 0;
                result = i + 1;
            }
        }
        // 如果出发节点是数组尾部，则没有有节点可以遍历循环图
        if (result == gas.size()){
            return -1;
        }    
        // 从起始节点开始检查之前循环的路径能否走完
        for (int i = 0; i < result; i++){
            sum += gas[i];
            if (sum < 0){
                return -1;
            }
        }
        return result;
    }
};