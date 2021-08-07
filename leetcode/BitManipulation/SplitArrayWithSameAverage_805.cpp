#include <header.h>
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double sum = 0.0;
        for(auto x : nums) sum += x;
        double avg = sum / 2.0;
        
    }
};


int main(){

}