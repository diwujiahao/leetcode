/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    deque<TreeNode*> data; // 双端队列辅助存储临时数据
    vector<vector<int>> result; // 存储返回结果
    int count = 0; // 统计正序倒叙转换
    bool direction = false; // 当前正序/倒叙
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 特殊情况判断
        if (!root){
            return result;
        }
        // 初始化队列 放入根节点
        data.push_back(root);
        // 循环
        while (!data.empty()){
            // count = 0 表示一层遍历完 需要调换方向 并向result加入新容器
            if (count == 0){
                result.push_back(vector<int>());
                count = int(data.size());
                direction = !direction;
            }
            // 取出当前节点并加入结果容器result中
            TreeNode* temp;
            if (direction){
                temp = data.front();
                data.pop_front();
            }
            else{
                temp = data.back();
                data.pop_back();
            }
            result.back().push_back(temp->val);
            count--;
            // 将当前节点的子节点按照正确的  顺序和方向  加入队列data中
            if (temp->left){
                if (direction){
                    data.push_back(temp->left);
                    if (temp->right){
                        data.push_back(temp->right);
                    }
                }
                else{
                    if (temp->right){
                        data.push_front(temp->right);
                    }
                    data.push_front(temp->left);
                }
            }
            else{
                if (temp->right){
                    if (direction){
                        data.push_back(temp->right);
                    }
                    else{
                        data.push_front(temp->right);
                    }
                }
            }
            
        }
        return result;
    }
};









class Solution {
    deque<TreeNode*> data; // 双端队列辅助存储临时数据
    vector<vector<int>> result; // 存储返回结果
    int count = 0; // 统计正序倒叙转换
    bool direction = false; // 当前正序/倒叙
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 特殊情况判断
        if (!root){
            return result;
        }
        // 初始化队列 放入根节点
        data.push_back(root);
        // 循环
        while (!data.empty()){
            // count = 0 表示一层遍历完 需要调换方向 并向result加入新容器
            if (count == 0){
                result.push_back(vector<int>());
                count = int(data.size());
                direction = !direction;
            }
            // 取出当前节点并加入结果容器result中
            TreeNode* temp;
            if (direction){
                temp = data.front();
                data.pop_front();
            }
            else{
                temp = data.back();
                data.pop_back();
            }
            result.back().push_back(temp->val);
            count--;
            // 将当前节点的子节点按照正确的  顺序和方向  加入队列data中
            if (direction){
                if (temp->left){
                    data.push_back(temp->left);
                }
                if (temp->right){
                    data.push_back(temp->right);
                }
            }
            else{
                if (temp->right){
                     data.push_front(temp->right);
                }
                if (temp->left){
                     data.push_front(temp->left);
                }
                
            } 
        }
        return result;
    }
};
