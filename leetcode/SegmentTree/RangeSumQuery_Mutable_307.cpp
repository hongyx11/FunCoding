#include <header.h>
/*
307. Range Sum Query - Mutable

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

*/


class NumArray {
public:
    vector<long long int> tree;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        tree.resize(4 * nums.size(), 0);
        for(auto x : nums) this->nums.push_back(x);
        build(0, 0, nums.size()-1);
    }
    int build(int index, int L, int R){
        if(L == R){
            tree[index] = nums[L];
            return tree[index];
        }
        int mid = L + (R-L) / 2;
        tree[index] = build(2*index+1, L, mid) + build(2*index+2, mid+1, R);
        return tree[index];
    }
    void update(int index, long long int val) {
        long long int diff = val - nums[index];
        int i = 0;
        nums[index] = val;
        int mid, L=0, R=nums.size()-1;
        while(true){
            tree[i] += diff;
            if(L == R) break;
            mid = L + (R-L) / 2;
            if(index <= mid){
                i = 2*i + 1;
                R = mid;
            }else{
                i = 2*i + 2;
                L = mid+1;
            }
        }
    }

    long long int sumRange(int left, int right) {
        return sumRange_helper(0, left, right, 0, nums.size()-1);
    }
    
    long long int sumRange_helper(int index, int left, int right, int L, int R){
        
        if(left <= L && right >= R) return tree[index];
        if(left > R || right < L) return 0;
        int mid = L + (R-L)/2;
        return sumRange_helper(2*index+1, left, right, L, mid) + sumRange_helper(2*index+2, left, right, mid+1, R);
    }
};



int main(){
    vector<int>nums = {1,3,5};
    NumArray na(nums);
    na.sumRange(0,2);
    na.update(1,2);
    return 0;

}