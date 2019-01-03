class Solution {
public:
    string simplifyPath(string path) {
        vector<string> memory;
        string temp = "";
        //存储路径至path
        for (int i = 0; i < path.size(); i++){
            if (path[i] == '/'){
                if (temp.size() > 0){
                    memory.push_back(temp);
                }
                temp = "";
                continue;
            }
            else if (path[i] == '.' && i + 1 < path.size() && path[i+1] == '.' && i + 2 < path.size() && path[i+2] != '/'){
                while(i < path.size() && path[i] != '/'){
                    temp += path[i];
                    i++;
                }
                memory.push_back(temp);
                temp = "";
            }
            else if (path[i] == '.' && i + 1 < path.size() && path[i+1] == '.'){
                if (!memory.empty()){
                    memory.erase(memory.begin() + memory.size() - 1);
                }
            }
            else if (path[i] == '.' && i + 1 < path.size() && path[i+1] != '/'){
                while(i < path.size() && path[i] != '/'){
                    temp += path[i];
                    i++;
                }
                memory.push_back(temp);
                temp = "";
            }
            else if (path[i] == '.'){
                continue;
            }
            else{
                temp += path[i];
            }
        }
        if (temp.size() > 0){
            memory.push_back(temp);
        }
        //生成新路径
        temp = "";
        for (int i = 0; i < memory.size(); i++){
            temp += '/';
            temp += memory[i];
        }
        return temp.size() > 0 ? temp : "/";
    }
};