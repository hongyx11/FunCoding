#include <header.h>

/*
1690. Stone Game VII

Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the 
leftmost stone or the rightmost stone from the row and receive points equal to the sum of 
the remaining stones' values in the row. The winner is the one with the higher score when 
there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to 
minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone 
from the left, return the difference in Alice and Bob's score if they both play optimally.

*/


class Solution {
public:
    int stoneGameVII(vector<int>& st) {
        vector<int> pf(st.size() + 1,0);
        for(int i=0; i<st.size(); i++){
            pf[i+1] = pf[i] + st[i];
        }
        vector<vector<int>> dp(st.size()+1, vector<int>(st.size()+1,0));
        int n = st.size();
        for(int dis = 0; dis <= n-1; dis++){
            for(int i=0; i<n; i++){
                int j = i + dis;
                if(j >= n) continue;
                if(i == j) dp[i][j] = 0;
                else if(i+1 == j) dp[i][j] = max(st[i], st[j]);
                else{
                    dp[i][j] = max(pf[j+1] - pf[i+1] - dp[i+1][j], pf[j] - pf[i] - dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};


int main(){
    return 0;    
}