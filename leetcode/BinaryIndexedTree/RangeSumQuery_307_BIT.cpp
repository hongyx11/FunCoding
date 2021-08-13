#include <header.h>
#include <BinaryIndexedTree.h>
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
    BinaryIndexedTree bit;
    NumArray(vector<int>& nums){
        bit.Init(nums);
    }
    
    void update(int index, int val) {
        bit.UpdateTree(index, val);
    }
    
    int sumRange(int left, int right) {
        int rightval = bit.PrefixSum(right+1);
        int leftval = bit.PrefixSum(left);
        return rightval - leftval;
    }
};

int main(){
    vector<int> nums = {1,3,5};
    NumArray a(nums);
    int r1 = a.sumRange(0,2);
    a.update(1,2);
    int r2 = a.sumRange(0,2);
    return 0;
}