#include <header.h>

/*
1649. Create Sorted Array through Instructions

Given an integer array instructions, you are asked to create a sorted array 
from the elements in instructions. You start with an empty container nums. 
For each element from left to right in instructions, insert it into nums. 
The cost of each insertion is the minimum of the following:
The number of elements currently in nums that are strictly less than instructions[i].
The number of elements currently in nums that are strictly greater than instructions[i].
For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) 
(elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].
Return the total cost to insert all elements from instructions into nums. Since the answer 
may be large, return it modulo 109 + 7
*/

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        vector<int> a;
        int il;
        int cost = 0;
        int is, ie;
        for(auto x : instructions){
            il = bs_1(x, a);
            if(a.empty()){
                a.push_back(x);
            }else{
                is = ie = il;
                while(is >= 0 && a[is] == x) is--;
                while(ie < a.size() && a[ie] == x) ie++;
                int c1 = max(0, is+1);
                int c2 = max(0, (int)a.size()-ie);
                cost += min(c1,c2);
            }
        }
        return cost;
    }
    int bs_1(int val, vector<int> &a){
        int l = 0, r = a.size();
        int mid;
        while(l < r){
            mid = l + (r-l) / 2;
            if(a[mid] <= val) l = mid+1;
            else r = mid; 
        }
        return l;
    }
};

int main(){
    vector<int> a = {1,5,6,2};
    Solution s1;
    int res = s1.createSortedArray(a);
    return res;
}