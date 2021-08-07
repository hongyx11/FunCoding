#include <header.h>

/*

1268. Search Suggestions System

Given an array of strings products and a string searchWord. 
We want to design a system that suggests at most three product names from products 
after each character of searchWord is typed. Suggested products should have common 
prefix with the searchWord. If there are more than three products with a common prefix 
return the three lexicographically minimums products.
Return list of lists of the suggested products after each character of searchWord is typed. 

*/



struct TrieNode{
    set<string> st;
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
            ptr->st.insert(word);
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


class Solution {
public:
    void helper(TrieNode *ptr, vector<string> &cur, string prefix){
        if(ptr->endpoint) cur.push_back(prefix);
        for(auto it = ptr->children.begin(); it != ptr->children.end(); it++){
            helper(it->second, cur, prefix + it->first);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie prefixtree;
        for(auto x : products) prefixtree.insert(x);
        vector<vector<string>> res;
        TrieNode *ptr = prefixtree.root;
        string prefix = "";
        for(auto x : searchWord){
            if(ptr == nullptr){
                res.push_back({});
            }else{
                if(ptr->children.find(x) != ptr->children.end()){
                    // vector<string> cur;
                    prefix += x;
                    ptr = ptr->children[x];
                    // helper(ptr, cur, prefix);
                    vector<string> cur = vector<string>(ptr->st.begin(), ptr->st.end());
                    sort(cur.begin(), cur.end());
                    if(cur.size() > 3) cur.resize(3);
                    res.push_back(cur);
                }else{
                    res.push_back({});
                    ptr = nullptr;
                }
            }
        }
        return res;
    }
    
};