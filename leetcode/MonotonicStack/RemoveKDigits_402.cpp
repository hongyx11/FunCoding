#include <header.h>


/*

402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num. 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> vec;
        if(k >= num.size())return "0";
        for(auto x : num){
            if(k == 0) vec.push_back(x);
            else
            {
                if(vec.empty() || vec.back() <= x){
                    vec.push_back(x);
                }else{
                    while(!vec.empty() && k > 0 && vec.back() > x){
                        vec.pop_back();
                        k--;
                    }
                    vec.push_back(x);
                }
            }
        }
        int idx = 0;
        
        vector<char> tmp;
        while(idx != vec.size() && vec[idx] == '0') idx++;
        for(int i=idx; i<vec.size(); i++){
            tmp.push_back(vec[i]);
        }
        vec = tmp;
        if(k > vec.size() || vec.size() == 0) return "0";
        string res = string(vec.begin(), vec.begin() + vec.size() - k);
        return res;
    }
};

int main(){
    string num = "9";
    int k = 1;
    Solution s1;
    string res = s1.removeKdigits(num, k);
    return 0;
}