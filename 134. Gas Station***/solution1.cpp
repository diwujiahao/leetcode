class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 遍历起点
        for (int i = 0; i < gas.size(); i++){
            int index = i;
            int tank = 0;
            // 模拟行驶
            while(1){
                tank = tank + gas[index] - cost[index];
                // 如果油量小于0，则无法遍历，跳出
                if (tank < 0){
                    break;
                }
                // 行驶下一站
                index = (index + 1) % gas.size();
                // 行驶结束，返回结果
                if (index == i){
                    return i;
                }
            }
        }
        return -1;
    }
};