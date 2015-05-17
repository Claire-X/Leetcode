//Trie
class TrieNode{
public:
    bool end;
    TrieNode* child[26];
    TrieNode(){
        end = false;
        fill_n(child,26,nullptr);
    }
};
class WordDictionary {

public:
    TrieNode* root;

    WordDictionary(){
        root = new TrieNode;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!node->child[c-'a'])
                node->child[c-'a'] = new TrieNode;
            node = node->child[c-'a'];
        }
        node->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root,word);
    }
    bool search(TrieNode* t, string word) {
        for(int i =0;i<word.length();i++){
            char c = word[i];
            if(c=='.'){
                for(int j=0;j<26;j++){
                	if(t->child[j]){
                		if(i == word.length()-1){
                			if(t->child[j]->end) return true;
                		}
                		else if(search(t->child[j],word.substr(i+1,word.size()-i-1)))
                			return true;
                	}
                }
                return false;
            }
           if(!t->child[c-'a']) return false;
           t = t->child[c-'a'];
        }
        return t->end;
    }
};
