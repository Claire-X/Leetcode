// if delete function is needed, add a int share in TrieNode, once share = 0, delete the trie whose root is the current node
class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> suc;
    bool end;
    TrieNode() {
        suc.resize(26);
        end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* it = root;
        for(auto c:s){
            if(!it->suc[c-'a'])
                it->suc[c-'a'] = new TrieNode();
            it = it->suc[c-'a'];
        }
        it->end = true;
    }

    bool search(string key) {
        TrieNode* it = root;
        for(auto c:key){
            if(!it->suc[c-'a'])
                return false;
            it = it->suc[c-'a'];
        }
        return it->end;
    }

    bool startsWith(string prefix) {
        TrieNode* it = root;
        for(auto c:prefix){
            if(!it->suc[c-'a'])
                return false;
            it = it->suc[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
