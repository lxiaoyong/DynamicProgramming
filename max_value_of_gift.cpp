//
// Created  on 2020/8/23.
//题目：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
#include <vector>
using namespace std;
/*
 * if grid =
 * [ [1,3,1, 1 ]
 *   [1,5,1,100]
 *   [4,2,1, 1 ] ]
 *
 *  dp=[ [1,4, 5,  6 ]
 *       [2,9, 10,110]
 *       [6,11,12,111]
 *
 *  简化: first dp = [1，4，5，6]
 *       next dp=[2,4,5,6]
 *       next dp=[2,9,5,6]
 *       ....
 *       last dp=[6,11,12,111]
 * */
int maxValue(vector<vector<int>>& grid) {
    int row_len=grid.size(),column=grid[0].size();
    vector<int> dp(column,grid[0][0]);
    for(int i=1;i<column;++i)
        dp[i]=dp[i-1]+grid[0][i];
    for(int r=1;r<row_len;++r){
        dp[0]+=grid[r][0];
        for(int c=1;c<column;++c){
            dp[c]=grid[r][c]+max(dp[c-1],dp[c]);
        }
    }
    return dp[column-1];
}