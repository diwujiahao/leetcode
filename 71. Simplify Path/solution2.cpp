class Solution {
public:
    string simplifyPath(string path) {
        vector<string> memory;
        int i = 0;
        //存储路径至path
        while (i < path.size()){
            if (path[i] == '/'){
                while(i < path.size() && path[i] == '/'){
                    i++;
                }
            }
            else if (path[i] == '.'){
                string temp = "";
                while(i < path.size() && path[i] != '/'){
                    temp += path[i];
                    i++;
                }
                if (temp == ".."){
                    if (!memory.empty()){
                        memory.erase(memory.begin() + memory.size() - 1);
                    }
                }
                else if (temp == "."){}
                else{
                    memory.push_back(temp);
                }
            }
            else{
                string temp = "";
                while(i < path.size() && path[i] != '/'){
                    temp += path[i];
                    i++;
                }
                memory.push_back(temp);
            }
        }
        //生成新路径
        string temp = "";
        for (int i = 0; i < memory.size(); i++){
            temp += '/';
            temp += memory[i];
        }
        return temp.size() > 0 ? temp : "/";
    }
};
