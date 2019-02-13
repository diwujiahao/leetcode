/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    
    queue<TreeLinkNode*> data;
    int count = 0;
    
public:
    void connect(TreeLinkNode *root) {
        if (!root){
            return;
        }
        data.push(root);
        
        while(!data.empty()){ 
            if (count == 0){
                count = data.size();
            }
            // 遍历当前节点
            count--;
            TreeLinkNode* temp = data.front();
            data.pop();
            temp->next = (count == 0) ? nullptr : data.front();
            // 压入左右子节点
            if (temp->left){
                data.push(temp->left);
            }
            if (temp->right){
                data.push(temp->right);
            }
        }
        
    }
};