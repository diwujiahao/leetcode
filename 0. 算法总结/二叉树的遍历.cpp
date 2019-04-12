class Solution{

	// 先序遍历2
	vector<int> pre_order2(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> data;
        if (!root){
            return result;
        }
        data.push(root);
        while (!data.empty()){
            // 出栈一个元素
            TreeNode* temp = data.top();
            data.pop();
            // 访问
            result.push_back(temp->val);
            // 存入左右子树
            if (temp->right){
                data.push(temp->right);
            }
            if (temp->left){
                data.push(temp->left);
            }
        }
        return result;
    }

    // 后序遍历2
    vector<int> postorderTraversal(TreeNode* root) {
    	stack<TreeNode*> data; // 辅助栈1
    	stack<int> s2; // 辅助栈2 = 输出结果的逆序
    	vector<int> result; // 输出结果
        if (!root){
            return result;
        }
        data.push(root);
        while(!data.empty()){
            TreeNode* temp = data.top();
            data.pop();
            s2.push(temp->val);
            if (temp->left){
                data.push(temp->left);
            }
            if (temp->right){
                data.push(temp->right);
            }
        }
        while(!s2.empty()){
            result.push_back(s2.top());
            s2.pop();
        }
        return result;
    }
    
public:
	// 先序遍历1
	vector<int> pre_order1(TreeNode* root){
        vector<int> result; // 存储结果变量
        stack<TreeNode*> data; // 辅助栈
        TreeNode* point = root; // 辅助指针
        if (!root){
            return result;
        }
        while (point || !data.empty()){
            while (point){
                result.push_back(point->val); // 先序访问
                data.push(point);
                point = point->left;
            }
            if (!data.empty()){
                point = data.top();
                data.pop();
                point = point->right;
            }
        }
        return result;
    }


    // 中序遍历1
    vector<int> in_order(TreeNode* root){
        vector<int> result; // 存储结果变量
        stack<TreeNode*> data; // 辅助栈
        TreeNode* point = root; // 辅助指针
        if (!root){
            return result;
        }
        while (point || !data.empty()){
            while (point){
                data.push(point);
                point = point->left;
            }
            if (!data.empty()){
                point = data.top();
                data.pop();
                result.push_back(point->val); // 中序访问
                point = point->right;
            }
        }
        return result;
    }

    // 后序遍历1
    vector<int> post_order(TreeNode* root){
        vector<int> result; // 存储结果变量
        stack<TreeNode*> data; // 辅助栈
        TreeNode* point = root; // 辅助指针1
        TreeNode *last_visit = nullptr; // 辅助指针2
        if (!root){
            return result;
        }
        while (point || !data.empty()){
            while (point){
                data.push(point);
                point = point->left;
            }
            if (!data.empty()){
                point = data.top();
                // 若无右子树 或 右子树已经遍历过
                if (!point->right || last_visit == point->right){
                    result.push_back(point->val); // 后序访问
                    data.pop();
                    last_visit = point;
                    point = nullptr;
                }
                // 否则指向右子树
                else{
                    point = point->right;
                }
            }
        }
        return result;
    }

};





















