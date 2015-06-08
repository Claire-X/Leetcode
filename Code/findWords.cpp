class TrieNode{
public:
    bool end;
    TrieNode* children[26];
    TrieNode(){
        end = false;
        fill_n(children,26,nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string s){
        TrieNode* n = root;
        for(int i=0;i<s.size();i++){
            if(!n->children[s[i]-'a']){
                n->children[s[i]-'a'] = new TrieNode();
            }
            n = n->children[s[i]-'a'];
            if(i==s.size()-1) n->end = true;
        }
    }
    void buildTrie(vector<string> &words){
        for(string s:words){
            insert(s);
        }
    }
    void check(TrieNode* n,vector<vector<char>>& board,int i,int j,string str,vector<string>& res){
    	if(board[i][j]=='*') return;
        if(!n->children[board[i][j]-'a']) return;
        n = n->children[board[i][j]-'a'];
        str+=board[i][j];
        board[i][j] = '*';
        if(n->end) {res.push_back(str);n->end=false;}
        if(i+1<board.size()) check(n,board,i+1,j,str,res);
        if(i-1>=0) check(n,board,i-1,j,str,res);
        if(j+1<board[0].size()) check(n,board,i,j+1,str,res);
        if(j-1>=0) check(n,board,i,j-1,str,res);
        board[i][j] = str.back();
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie trie;
        trie.buildTrie(words);
        for(int i =0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                trie.check(trie.root,board,i,j,"",res);
        return res;
    }
};
