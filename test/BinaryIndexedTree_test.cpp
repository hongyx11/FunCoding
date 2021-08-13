#include <header.h>
#include <BinaryIndexedTree.h>
#include <gtest/gtest.h>
namespace {

    class BinaryIndexedTreeTest : public testing::Test {
        protected:
        BinaryIndexedTree bit;
        vector<int> nums;
        vector<int> ans;
        vector<int> prefixans;
        void SetUp() override {
            // nums = {5,2,9,-3,5,20,10,-7,2,3,-4,0,-2,15,5};
            // ans =  {0,5,7,9,13,5,25,10,41,2,5,-4,1,-2,13,5};
            nums = {1, 3, 5};
            ans = {0, 1, 4, 5};
            prefixans.resize(nums.size()+1, 0);
            for(int i=1; i<nums.size()+1; i++){
                prefixans[i] = prefixans[i-1] + nums[i-1];
            }
            bit.Init(nums);
        }
    };

    TEST_F(BinaryIndexedTreeTest, Init){
        for(int i=0; i<ans.size(); i++){
            EXPECT_EQ(bit.arrays[i], ans[i]);
        }
    }
    TEST_F(BinaryIndexedTreeTest, PrefixSum){
        for(int i=0; i<nums.size(); i++){
            EXPECT_EQ(bit.PrefixSum(i), prefixans[i]);
        }
    }
    TEST_F(BinaryIndexedTreeTest, UpdateTree){
        vector<int> randnum(bit.nums.size(), 0);
        for(int i=0; i<nums.size(); i++) randnum[i] = rand() % 20;
        for(int i=0; i<nums.size(); i++){
            
            bit.UpdateTree(i, randnum[i]);
            vector<int> newnums(bit.nums.begin(), bit.nums.end());
            BinaryIndexedTree newbit;
            newbit.Init(newnums);
            bool allmatch = true;
            for(int j=0; j<nums.size(); j++){
                if(bit.arrays[j] != newbit.arrays[j]){
                    allmatch = false;
                    break;
                }
            }
            EXPECT_EQ(allmatch, true);            
        }
    }
}



int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}