//
// Created  on 2020/10/12.
// https://leetcode-cn.com/problems/triangle/

#include<vector>
using namespace std;
/*
 * 二维dp数组定义dp[i][j]为三角形第i层第j个数到最底层的最小路径和
 * 可化简为一维dp数组
 * */
int minimumTotal(vector<vector<int>>& triangle) {
    int r=triangle.size();
    vector<int> dp=triangle[r-1];
    for(int row=r-2;row!=-1;--row){
        for(int col=0;col<=row;++col){
            dp[col] = triangle[row][col]+min(dp[col],dp[col+1]);
        }
    }
    return dp[0];
}