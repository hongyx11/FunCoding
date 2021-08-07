#include <header.h>


struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool endpoint;
};

class Trie {
public:
    TrieNode * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * ptr = root;
        for(int i=0; i<word.size(); i++){
            if(ptr->children.find(word[i]) != ptr->children.end()){
                ptr = ptr->children[word[i]];
            }else{
                ptr->children[word[i]] = new TrieNode();
                ptr = ptr->children[word[i]];
            }
        }
        ptr->endpoint = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * ptr = root;
        for(int i=0; i<word.size(); i++){
            if(ptr->children.find(word[i]) != ptr->children.end()){
                ptr = ptr->children[word[i]];
            }else{
                return false;
            }
        }
        return ptr->endpoint == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * ptr = root;
        for(int i=0; i<prefix.size(); i++){
            if(ptr->children.find(prefix[i]) != ptr->children.end()){
                ptr = ptr->children[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    
}