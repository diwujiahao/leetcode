class Trie {
    
    struct node{
        bool is_word = false;
        unordered_map<char, node*> hash;
        node(bool label) : is_word(label){}
    };
    
    node *root = new node(false);
    
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        node* point = root;

        for (int i = 0; i < word.size(); i++){
            // 字符已存在
            if (point->hash.find(word[i]) != point->hash.end()){
                point = point->hash[word[i]];
            }
            // 不存在的字符
            else{
                point->hash[word[i]] = new node(false);
                point = point->hash[word[i]];
            }
            // 结尾处进行标记
            if (i == word.size()-1){
                point->is_word = true;
            }
        }
        return;
    }
    
//    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* point = root;
        for (int i = 0; i < word.size(); i++){
            // 字符已存在
            if (point->hash.find(word[i]) != point->hash.end()){
                point = point->hash[word[i]];
            }
            // 不存在的字符
            else{
                return false;
            }

        }
        return point->is_word;
    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* point = root;
        for (int i = 0; i < prefix.size(); i++){
            // 字符已存在
            if (point->hash.find(prefix[i]) != point->hash.end()){
                point = point->hash[prefix[i]];
            }
            // 不存在的字符
            else{
                return false;
            }

        }
        return !point->hash.empty() || point->is_word;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */