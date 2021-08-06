#include <header.h>


/*

Given an unsorted array of integers nums, 
return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> used;
        for(auto i:nums) used[i] = false;
        int longest = 0;
        for(auto i:nums){
            if(used[i]) continue;
            int length = 1;
            used[i] = 1;
            for(int j = i+1;used.find(j)!=used.end();++j){
                used[j] = true;
                ++length;
            }
            for(int j = i-1;used.find(j)!=used.end();--j){
                used[j] = true;
                ++length;
            }
            longest = max(longest,length);
        }
        return longest;
    }
};

int main(){

}