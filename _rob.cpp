//
// Created by at on 2020/7/17.
//
//    题目：https://leetcode-cn.com/problems/house-robber/

/*
 * 若房子只有一间，则直接选择这间；
 * 若房子有两间，则选择两间中价值更大的
 * 若要更多房间数，则原问题可以分解为子问题： 对于第 i (i>=2)个房间，若不偷这间，则目前最大金额为第(i-1)时的总金额；
 * 若偷，则最大金额为第(i-2)时总金额加上当前房子的金额；两者选最大金额作为当前房子时偷取的总金额
 * */
using namespace std;
#include <vector>
int rob(vector<int> nums) {
    int len=nums.size();
    if(len==0) return 0;
    if(len==1) return nums[0];
    if(len==2) return max(nums[0],nums[1]);
    vector<int> money(len,0);
    money[0]=nums[0];
    money[1]=max(nums[0],nums[1]);
    for(int i=2;i<len;++i){
        money[i]=max(money[i-1],money[i-2]+nums[i]);
    }
    return money[len-1];
}
