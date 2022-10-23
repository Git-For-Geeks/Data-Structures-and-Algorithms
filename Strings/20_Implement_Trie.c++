class TrieNode{
public :
    bool check = false;
    TrieNode * childs[26];
    TrieNode(){
        for(int i = 0; i <26; i++)
            childs[i] = NULL;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int idx = 0;
        TrieNode *node = root;
        for(auto c: word) {
            idx = c-'a';
            if(!node->childs[idx]){
                node->childs[idx] = new TrieNode();
            }
            else{
                node = node->childs[idx];
            }
        }
        node->check = true;
    }
    
    bool search(string word) {
        int idx = 0;
        TrieNode *node = root;
        for(auto c : word) {
            idx = c-'a';
            if(!node->childs[idx])
                return false;
            node = node->childs[idx];
        }
        return node->check;
    }
    
    bool startsWith(string prefix) {
        int idx = 0;
        TrieNode *node = root;
        for(auto c : prefix) {
            idx = c-'a';
            if(!node->childs[idx])
            {
                return false;
            }
            else{
                node = node->childs[idx];
            }
        }
        return true;
    }
};