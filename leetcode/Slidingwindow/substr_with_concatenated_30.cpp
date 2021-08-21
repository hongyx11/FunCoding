#include <header.h>

/*

30. Substring with Concatenation of All Words
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> wmap;
        for(auto x : words) {
            if(wmap.find(x) != wmap.end()) wmap[x]++;
            else wmap[x] = 1;
        }
        for(int i=0; i<words[0].size(); i++){
            vector<int> tmp = helper(s, i, wmap, words[0].size());
            for(auto x : tmp){
                cout << "i " << i << ", " << x << endl;
                res.push_back(x);
            }
        }
        return res;
    }
    vector<int> helper(string s, int index, unordered_map<string, int> &wmap, int wl){
        int i,j;
        i = j = index;
        unordered_map<string,int> tmpmap;
        tmpmap = wmap;
        vector<int> res;
        while(i < s.size()){
            bool find = false;
            if (j+ wl > s.size()){
                break;
            }
            while(tmpmap.find(s.substr(j, wl)) != tmpmap.end() && tmpmap[s.substr(j, wl)] > 0){
                tmpmap[s.substr(j,wl)]--;
                find = true;
                for(auto x =tmpmap.begin(); x!=tmpmap.end(); x++){
                    if(x->second > 0){
                        find = false;
                        break;
                    }
                }
                if(find) break;
                j += wl;
                if(j+wl > s.size()) break;
            }
            if(find) {
                res.push_back(i);
                i += wl;
                j = i;
                tmpmap = wmap;
            }else{
                if(tmpmap.find(s.substr(j, wl)) == tmpmap.end()) i = j+wl;
                else i = j;
                tmpmap = wmap;
            }
        }
        return res;
    }
};


int main(){
    Solution s1;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar", "foo","the"};
    vector<int> res = s1.findSubstring(s, words);
    REP(i, 0, res.size()-1){
        cout << res[i] << endl;
    }
    return 0;
}