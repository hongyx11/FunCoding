#include <header.h>
#include <BinaryIndexedTree.h>




void BinaryIndexedTree::Init(vector<int>& nums)
{
    arrays.clear();
    arrays.resize(nums.size()+1, 0);
    for(int i=1; i<=arrays.size(); i++) arrays[i] = nums[i-1];
    this->nums = vector<int>(nums.begin(), nums.end());
    BuildTree();
}

void BinaryIndexedTree::BuildTree()
{
    for(int i=1; i<arrays.size(); i++){
        int p = i + ( i & (-i) );
        if(p < arrays.size()){
            arrays[p] += arrays[i];
        }
    }
}

int BinaryIndexedTree::PrefixSum(int index)
{
    int sum = 0;
    while(index > 0){
        sum += arrays[index];
        index -= (index & (-index));
    }
    return sum;
}

void BinaryIndexedTree::UpdateTree(int index, int value)
{
    int diff = value - nums[index];
    nums[index] = value;
    index += 1;
    while(index <= nums.size()){
        arrays[index] += diff;
        index += (index & (-index)); 
    }
}