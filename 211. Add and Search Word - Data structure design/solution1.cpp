class WordDictionary {
    
    struct node{
        bool is_word = false;
        unordered_map<char, node*> data;
        node(bool label) : is_word(label){}
    };
    
    node* root = new node(false);
    
    bool find_word(string word, int i, node* point){
        // 结束条件
        if (!point){
            return false;
        }
        if (i >= word.size()){
            return point->is_word;
        }
        // 本位为 .
        if (word[i] == '.'){
            
            for (unordered_map<char, node*>::iterator iter = point->data.begin(); iter != point->data.end(); iter++){
                if (find_word(word, i+1, iter->second)){
                    return true;
                }
            }
            
            return false;
        }
        // 本位为字母
        else{
            return find_word(word, i+1, point->data[word[i]]);
        }
        
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node* point = root;
        for (int i = 0; i < word.size(); i++){
            // 找到了
            if (point->data.find(word[i]) != point->data.end()){
                point = point->data[word[i]];
            }
            // 没找到
            else{
                point->data[word[i]] = new node(false);
                point = point->data[word[i]];
            }
        }
        point->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find_word(word, 0, root);
    }
};
